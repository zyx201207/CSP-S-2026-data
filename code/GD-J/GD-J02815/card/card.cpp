#include<bits/stdc++.h>
using namespace std;

const int N=5e5;

int n,m;
int a[N],num[N];

bool check(int x,int s[],int sxb){
	for(int i=1;i<=sxb;i++){
		if(s[i]==x)return true;
	}
	return false;
}

int main(){
	freopen("card.in","r",stdin);
	frepoen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++){
		int stp[N],stpxb=1;
		memset(stp,0,sizeof(stp));
		for(int j=i;j<=n;j++){
			if(check(a[j],stp,stpxb)){
				memset(stp,0,sizeof(stp));
				stpxb=1;
			}
			stp[stpxb++]=a[j];
		}
		for(int j=1;j<=stpxb;j++){
			num[stp[i]]++;
		}
		for(int i=1;i<=m;i++)cout<<num[i]<<" ";
		cout<<endl;
	}
	
	for(int i=1;i<=m;i++)cout<<num[i]<<" ";
	
	return 0;
}
