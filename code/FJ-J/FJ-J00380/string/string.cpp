#include<bits/stdc++.h>
#define int long long
using namespace std;
//评测机hao强，居然是高贵的Ultra9大人 
int n,len;
int a[200005];
int s[200005][26];
char c[200005];
int l[200005],r[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l[i]=len+1;
		len+=a[i];
		r[i]=len;
		s[i][c[i]-'a']=a[i];
		for(int j=0;j<26;j++){
			s[i][j]+=s[i-1][j];
		}
	}
	int mid=(len+1)/2,ans=0;
	for(int i=1;i<=n;i++){
		if(l[i]>mid){
			break;
		}
		r[i]=min(r[i],mid);
		int nl=len-r[i]+1,nr=len-l[i]+1;
		int L=1,R=n,MID,ans1=0,ans2=0;
		while(L<=R){
			MID=(L+R)/2;
			if(r[MID]>=nl){
				ans1=MID;
				R=MID-1;
			}else{
				L=MID+1;
			}
		}
		L=1,R=n,MID;
		while(L<=R){
			MID=(L+R)/2;
			if(l[MID]<=nr){
				ans2=MID;
				L=MID+1;
			}else{
				R=MID-1;
			}
		}
		if(ans1==ans2){
			if(c[ans1]!=c[i]){
				ans+=nr-nl+1;
//				cout<<nr-nl+1<<"\n";
			}
			continue;
		}
		if(c[ans1]!=c[i]){
			ans+=r[ans1]-nl+1;
//			cout<<r[ans1]-nl+1<<"\n";
		}
		if(c[ans2]!=c[i]){
			ans+=nr-l[ans2]+1;
//			cout<<nr-l[ans2]+1<<"\n";
		}
		for(int j=0;j<26;j++){
			if(c[i]-'a'!=j){
				ans+=s[ans2-1][j]-s[ans1][j];
//				cout<<s[ans2-1][j]-s[ans1][j]<<"\n";
			}
		}
	}
	cout<<ans;
	return 0;
}
