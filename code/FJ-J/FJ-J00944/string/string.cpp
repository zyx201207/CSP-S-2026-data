#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
	return;
}
int n,a[200005],aa[200005],aaa[200005];
long long sum;
char c[200005],cc[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		sum+=a[i];
		cin>>c[i];
	}
	if(sum%2==0){
		int k=sum/2,cnta=0,cnt2=0;
		bool pd=true;
		sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			if(sum<=k){
				aa[++cnta]=a[i];
				cc[cnta]=c[i];
			}else if(sum>k&&pd){
				aa[++cnta]=a[i]-sum+k;
				cc[cnta]=c[i];
				aa[++cnta]=sum-k;
				cc[cnta]=c[i];
				pd=false;
			}else{
				aa[++cnta]=a[i];
				cc[cnta]=c[i];
			}
		}
		for(int i=1;i<=cnta;i++){
			if(aa[i]!=0) a[++cnt2]=aa[i],c[cnt2]=cc[i];
		}
//		for(int i=1;i<=cnt2;i++){
//			write(a[i]);
//			printf(" ");
//			cout<<c[i]<<endl;
//		}
		int ans=0,last=0,last2=0;
		int i=1,j=cnt2;
		while(1){
			if(!last&&!last2){
				if(a[i]==a[j]){
					if(c[i]!=c[j]) ans+=a[i];
				}else if(a[i]>a[j]){
					if(c[i]==c[j]) last=a[i]-a[j];
					else{
						ans+=a[j];
						last=a[i]-a[j];
					}
				}else{
					if(c[i]==c[j]) last2=a[j]-a[i];
					else{
						ans+=a[i];
						last2=a[j]-a[i];
					} 
				}
			}else if(last){
				if(a[j]>last){
					if(c[i]==c[j]){
						
					}
					else ans+=last;
					last2=a[j]-last;
					last=0;
				}else if(a[j]==last){
					if(c[j]==c[i]){
						
					}
					else ans+=last;
					last=0;
				}else{
					if(c[i]==c[j]) last-=a[j];
					else{
						ans+=a[j];
						last-=a[j];
					}
				}
			}else if(last2){
				if(a[i]>last2){
					if(c[i]==c[j]){
						
					}
					else ans+=last2;
					last=a[i]-last2;
					last2=0;
				}else if(a[i]==last2){
					if(c[j]==c[i]) last2=0;
					else ans+=last2;
					last2=0;
				}else{
					if(c[i]==c[j]) last2-=a[i];
					else{
						ans+=a[i];
						last2-=a[i];
					}
				}
			}
			if(i+1==j) break;
			if(!last&&!last2) i++,j--;
			else if(last) j--;
			else if(last2) i++;
		}
		write(ans);
	}else{
		int k=sum/2+1;
		bool pd2=true;
		sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			if(sum>=k&&pd2){
				a[i]--;
				pd2=false;
			}
		}
		sum--;
		k=sum/2;
		int cnta=0,cnt2=0;
		bool pd=true;
		sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			if(sum<=k){
				aa[++cnta]=a[i];
				cc[cnta]=c[i];
			}else if(sum>k&&pd){
				aa[++cnta]=a[i]-sum+k;
				cc[cnta]=c[i];
				aa[++cnta]=sum-k;
				cc[cnta]=c[i];
				pd=false;
			}else{
				aa[++cnta]=a[i];
				cc[cnta]=c[i];
			}
		}
		for(int i=1;i<=cnta;i++){
			if(aa[i]!=0) a[++cnt2]=aa[i],c[cnt2]=cc[i];
		}
		int ans=0,last=0,last2=0;
		int i=1,j=cnt2;
		while(1){
			if(!last&&!last2){
				if(a[i]==a[j]){
					if(c[i]!=c[j]) ans+=a[i];
				}else if(a[i]>a[j]){
					if(c[i]==c[j]) last=a[i]-a[j];
					else{
						ans+=a[j];
						last=a[i]-a[j];
					}
				}else{
					if(c[i]==c[j]) last2=a[j]-a[i];
					else{
						ans+=a[i];
						last2=a[j]-a[i];
					}
				}
			}else if(last){
				if(a[j]>last){
					if(c[i]==c[j]){
						
					}
					else ans+=last;
					last2=a[j]-last;
					last=0;
				}else if(a[j]==last){
					if(c[j]==c[i]) last=0;
					else ans+=last;
					last=0;
				}else{
					if(c[i]==c[j]) last-=a[j];
					else {
						ans+=a[j];
						last-=a[j];
					}
				}
			}else if(last2){
				if(a[i]>last2){
					if(c[i]==c[j]){
						
					}
					else ans+=last2;
					last=a[i]-last2;
					last2=0;
				}else if(a[i]==last2){
					if(c[j]==c[i]) last2=0;
					else ans+=last2;
					last2=0;
				}else{
					if(c[i]==c[j]) last2-=a[i];
					else {
						ans+=a[i];
						last2-=a[i];
					}
				}
			}
//			write(i);
//			printf(" ");
//			write(j);
//			printf(" ");
//			write(last);
//			printf(" ");
//			write(last2);
//			printf(" ");
//			write(ans);
//			cout<<endl;
			if(i+1==j) break;
			if(!last&&!last2) i++,j--;
			else if(last) j--;
			else if(last2) i++;
		}
		write(ans);
	}
	return 0;
}
/*
6
2 a
3 b
2 c
2 a
3 b
1 c
*/
