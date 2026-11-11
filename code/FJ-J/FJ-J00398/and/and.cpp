#include <bits/stdc++.h>
using namespace std;
const int N=2e5+15;
int n,m,maxb;
int a[N];
vector<int> v;
void GETBIT(){
	int num=a[n],cnt=0;
	while(num){
		num>>=1;
		cnt++;
	}
	maxb=cnt;
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	GETBIT();
	for(int i=maxb;i>=1;i--){
		v.clear();
		int ps=1<<i;
		for(int j=n;j>=1;j--){
			if(a[j]/ps==1)
				v.push_back(a[j]);
			if(v.size()==m){
				int sum=v[0];
				for(int k=1;k<v.size();k++)
					sum=sum & v[k];
				cout<<sum;
				return 0;
			}
			a[j]=a[j]%ps;
		}
	}
	cout<<0;
	return 0;
}
