#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char c;
}ot[200050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a;
	char ch;
	for(int i=1;i<=n;i++){
		cin>>a>>ch;
		ot[i].num=a;
		ot[i].c=ch;
	}
	long long ans=0;
	int l=1,r=n;
	while(l<r){	
			long long k=min(ot[l].num,ot[r].num);
			if(ot[l].c!=ot[r].c)ans+=k;
			ot[l].num-=k;
			ot[r].num-=k;
			if(ot[l].num==0)l++;
			if(ot[r].num==0)r--;	
	}
	cout<<ans;
} 
