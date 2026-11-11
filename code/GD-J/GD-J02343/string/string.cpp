#include<bits/stdc++.h>
using namespace std;
int n;
char a[100005];
int l[100005];
int r[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;cin>>m;
		cin>>a[i];
		l[i]=r[i-1]+1;
		r[i]=l[i]+m-1;
	}
	int ans=0;
	int x=1,y=r[n];
	int i=1;
	int j=n;
	while(x<=y){
		if(x>=l[i] && x<=r[i]){
			if(y>=l[j] && y<=r[j]){
				if(a[x]!=a[y])ans+=1;
			}
			else j++;
		}
		else i++;
		if(x>=l[i] && x<=r[i]){
			if(y>=l[j] && y<=r[j]){
				if(a[x]!=a[y])ans+=1;
			}
			else j++;
		}
		else i++;
		x+=1;
		y-=1;
	}
//	for(int i=1;i<=n/2+1;i++){
//		if(i>=l[j1] && i<=r[j1]){
//			if(k-i>=l[j2] && k-i<=l[j2]){
//				if(a[j1]!=a[j2])ans+=min(r[j1]-l[j1],r[j2]-l[j2]);
//			}
//		else j2--;
//		}
//		else j1++;
//		if(i>=l[j1] && i<=r[j1]){
//			if(k-i>=l[j2] && k-i<=l[j2]){
//				if(a[j1]!=a[j2])ans+=min(r[j1]-l[j1],r[j2]-l[j2]);
//			}
//		}
//		i+=min(r[j1]-l[j1],r[j2]-l[j2]);
//		cout<<r[j2]-l[j2]<<endl;
//	}
	cout<<ans;
	return 0;
}
