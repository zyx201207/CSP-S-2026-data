#include<bits/stdc++.h>
using namespace std;
char a[100001];
string liwa;
long long a1[100001],q=0;//q¶¨Î» 
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	long long ad[1001];
	long long n;
	cin>>n;
	string s;
	long long q=0;
	int z=1,zong=0;
	int d=0;
	for(int i=0;i<n;i++){
		cin>>a1[i]>>a[i];
		d+=a1[i];
		for(int j=0;j<a1[i];j++){
			liwa[q+j]=a[i];
		}
		q+=a1[i];
	}
	int sd;
	if(d%2==0){
		sd=d/2;
	}else{
		d-=1;
		sd=d/2;
		d+=1;
	}
	
	int qian=0;
	for(int i=0;i<sd;i++){
		if(liwa[i]!=liwa[d-i]){
			qian++;
		}
	}
		cout<<qian;	
	return 0;
}

