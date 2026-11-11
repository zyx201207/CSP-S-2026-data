#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005],tot,n,m;
int st[500005],top,ex[500005],vi[500005],fi[500005],ans[500005],s1,s2,f;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],s2+=(a[i]!=a[i-1]);
	if(m<=2){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n]) s1++;
		}
		if(a[n]==1) cout<<n<<' '<<s1;
		else cout<<s1<<' '<<n;
	}
	else if(s2<=5000){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]) c[tot]++;
			else b[++tot]=a[i],c[tot]++;
		}
		n=tot;
		for(int i=1;i<=n;i++){
			memset(vi,0,sizeof(vi));
			top=0;
			for(int j=i;j<=n;j++){
				if(vi[b[j]]){
					while(st[top]!=b[j]) vi[st[top--]]=0;
					top--;
				}
				st[++top]=b[j];
				vi[b[j]]=1;
			}
			for(int j=1;j<=top;j++) ans[st[j]]+=c[i];
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	}
	else if(n<=5000){
		for(int i=1;i<=n;i++){
			memset(vi,0,sizeof(vi));
			top=0;
			for(int j=i;j<=n;j++){
				if(vi[a[j]]){
					while(st[top]!=a[j]) vi[st[top--]]=0;
					top--;
				}
				st[++top]=a[j];
				vi[a[j]]=1;
			}
			for(int j=1;j<=top;j++) ans[st[j]]++;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	}
	else{
		for(int i=n;i>=1;i--){
			if(vi[a[i]]==-1){
				while(a[st[top]]!=a[i]){
					ex[st[top]]=i;
					vi[a[st[top]]]=st[top];
					top--;
				}
				ex[i]=i;
				fi[i]=st[top];
				continue;
			}
			if(vi[a[i]]){
				while(st[top]<vi[a[i]]){
					ex[st[top]]=i;
					vi[a[st[top]]]=st[top];
					top--;
				} 
			}
			vi[a[i]]=-1;
			st[++top]=i;
		}
		for(int i=1;i<=n;i++){
			ans[a[i]]+=i-ex[i];
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	
	return 0;
} 
