#include<bits/stdc++.h>
using namespace std;
int a1[200010],a2[200010],n,d=0,ans=0,s1[200010],s2[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		string s;
		scanf("%d",&a1[i]);
		cin>>s;
		s1[i]=s[0]-'0';
		d+=a1[i];
	}
	for(int j=1;j<=n;j++){
		s2[j]=s1[n-j+1];
		a2[j]=a1[n-j+1];
	}
	int p=1,q=1;
	for(int y=0;y<=(d+d%2)/2;y+=min(a1[p],a2[q])){
		int o;
		if(s1[p]!=s2[q]){
			ans+=min(a1[p],a2[q]);
		}
		if(a1[p]>a2[q]){
			a1[p]-=a2[q];
			q++;
		}else{
			if(a1[p]<a2[q]){
				a2[q]-=a1[p];
				p++;
			}else{
				if(a1[p]==a2[p]){
					p++;
					q++;
				}
			}
		}
	}
	printf("%d",ans-1);
	return 0;
}

