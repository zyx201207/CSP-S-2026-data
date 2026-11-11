//GZ-J00034，邵葛锦华，贵阳市观山湖区外国语实验中学 
#include<bits/stdc++.h>
using namespace std;
struct m{
	long long s;
	char f;
}a[200005];
char zfc[200005];
long long n,f[200];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	long long cnt=0;
	bool flag=1;
	char x;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].f;
		if(i==1) x=a[i].f;
		zfc[i]=a[i].f;
		cnt+=a[i].s;
		f[a[i].f-'a']+=a[i].s;
		if(a[i].f!=x) flag=0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		long long ans=-1;
		for(int i=0;i<='z'-'a';i++){
			ans=max(ans,f[i]);
		}
		cout<<cnt-ans;
		return 0;
	}else if(n<=10||cnt==n||cnt/50<=n){
		string k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].s;j++){
				k+=a[i].f;
			}
		}
		int len=k.size(),ans=0;
		int l=(len+1)/2;
		if(len%2==1){
			for(int i=l;i<=len;i++){
				if(k[i]!=k[l]){
					ans++;
				}
				l--;
			} 
		}else{
			l=len/2;
			for(int i=l+1;i<=len;i++){
				if(k[i]!=k[l]){
					ans++;
				}
				l--;
			} 
		}
		cout<<ans;
		return 0;
	}
	if(flag){
		cout<<0;
		return 0;
	}
	flag=1;
	int j=1;
	for(int i=n;i>j;i--){
		if(zfc[j]==zfc[i]&&a[i].s!=a[j].s||zfc[j]!=zfc[i]){
			flag=0;
		}
		j++;
	} 
	if(flag){
		cout<<0;
	}else{
		long long ans=-1;
		for(int i=0;i<='z'-'a';i++){
			ans=max(ans,f[i]);
		}
		cout<<cnt-ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

