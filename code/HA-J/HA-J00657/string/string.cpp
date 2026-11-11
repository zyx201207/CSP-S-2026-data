#include<bits/stdc++.h>
using namespace std;
int n,a[200101];
char c[200110];
long long ans = 0,al = 0,mid,s[200101];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d%c%c",&a[i],&c[i],&c[i]);
		al+=1LL*a[i];
		s[i] = s[i-1]+1LL*a[i];
	}
	if(al%2LL==0LL){
		mid = al/2;
	}else{
		mid = al/2+1;
	}
	int n1;
	for(int i = 1;i<=n;i++){
		if(s[i]<=mid&&s[i+1]>mid){
			n1 = i;
			break;	
		}
	}
	if(al%2LL==0LL){
		if(s[n1!=mid]){
			for(int i = n+1;i>=n1+2;i--){
				a[i] = a[i-1];
				c[i] = c[i-1];
			}
			a[n1+1] = s[n1+1]-mid;
			c[n1+1] = s[n1+1] - mid;
			n1++;
			n++;
		}
		for(int i = 1,j = n;i<n1;){
			if(a[i]<=a[j]){
				if(c[i]==c[j]){
					a[j]-=a[i];
					a[i] = 0;
				}else{
					ans+=1LL*a[i];
					a[j]-=a[i];
					a[i] = 0;
				}
			}else{
				if(c[i]==c[j]){
					a[i]-=a[j];
					a[j] = 0;
				}else{
					ans+=1LL*a[j];
					a[i]-=a[j];
					a[j] = 0;
				}
			}
			if(a[i]==0){
				i++;
			}
			if(a[j]==0){
				j--;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if(al%2LL==1LL){
		if(a[n1+1]!=1){
			if(s[n1]+1==mid){
				for(int i = n+1;i>=n1+2;i--){
					a[i] = a[i-1];
					c[i] = c[i-1];
				}		
				a[n1+2]--;
				a[n1+1] = 1;
				c[n1+1] = c[n1];
				n1++;
				n++;
			}else{
				for(int i = n+2;i>=n1+3;i--){
					a[i] = a[i-2];
					c[i] = c[i-2];
				}
				a[n1+2] = 1;
				a[n1+1] = (1LL*s[n1+1]-1LL*mid-1LL);
				a[n1+3] = a[n1+3]-1-a[n1+1];
				c[n1+2] = c[n1+3];
				c[n1+1] = c[n1+3];
				n1 = n1+2;
				n += 2;
			}
		}			
		for(int i  = 1,j = n;i<=n1-1;){
			if(a[i]<=a[j]){
				if(c[i]==c[j]){
					a[j]-=a[i];
					a[i] = 0;
				}else{
					ans+=1LL*a[i];
					a[j]-=a[i];
					a[i] = 0;
				}
			}else{
				if(c[i]==c[j]){
					a[i]-=a[j];
					a[j] = 0;
				}else{
					ans+=1LL*a[j];
					a[i]-=a[j];
					a[j] = 0;
				}			
			}
			if(a[i]==0){
				i++;
			}
			if(a[j]==0){
				j--;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
