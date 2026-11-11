#include<bits/stdc++.h>
using namespace std;
long long n,m,js;
vector<long long> a;
int b[5000000][2];
int a1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(long long i=0;i<n;i++){
		int w;
		cin>>w;
		a.push_back(w);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;){
		int x=a[i];
		int sum=0;
		while(a[i]==x){
			i++;
			sum++;
		}
	    b[js][0]=x;
		b[js][1]=sum;
		js++;
	}
	//cout<<js<<endl;
	//
	for(int i=1;i<js-1;i++){
		int xb=0,z=0,jc=b[i][0],an=0;
		for(int j=0;j<i;j++){
			xb+=b[j][1];
		}
		//cout<<xb<<endl;
		for(int j=xb-1;j>=0 && z<=m;){
			z+=jc-a[j];
			//cout<<z<<" "<<j<<endl;
			an++;
			j--;
		}
		//an--;
		an+=b[i][1];
		//cout<<an<<endl;
		//cout<<endl;
		a1=max(a1,an);
	}
	//cout<<endl;
	cout<<a1;
	return 0;
}
