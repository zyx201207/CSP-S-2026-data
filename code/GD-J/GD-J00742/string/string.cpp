#include<algorithm>
#include<iostream>
#include<cmath>
#define ll long long
#define F(i,x,y) for(int i=x;i<=y;i++)
#define F2(i,x,y) for(int i=x;i>=y;i--)
#define f(x,y) for(auto x:y)
#define lt(x) x&-x
#define d2(l,r) l+r>>1
#define ls(i) i<<1
#define rs(i) i<<1|1
using namespace std;
const int N=2e5+15;
ll n,a[N],b[N];
char ch[N],h[N];
int tot;
ll sum;
ll s1[N],s2[N],len1,len2;
char c1[N],c2[N];
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	cin>>n;
	F(i,1,n) cin>>a[i]>>ch[i];
	b[++tot]=a[1];
	h[tot]=ch[1];
	F(i,2,n){
		if(ch[i]==ch[i-1]) b[tot]+=a[i];
		else {
			b[++tot]=a[i];
			h[tot]=ch[i];
		}
	} 
	F(i,1,tot) sum+=b[i];
//	cout<<sum<<endl;
	ll s=0,len=((sum&1)?sum/2+1:sum/2),flag=0;
	F(i,1,tot){
		s+=b[i];
		if(s<len){
			s1[++len1]=b[i];
			c1[len1]=h[i];
		}else if(s==len){
			s1[++len1]=b[i]-(len&1);
			c1[len1]=h[i];
			flag=1;
		}else{
			if(!flag){
				flag=1;
				if((len-(len&1))-(s-b[i])>0){
					s1[++len1]=(len-(len&1))-s+b[i];
					c1[len1]=h[i];
				}
				s2[++len2]=s-len;
				c2[len2]=h[i];
			}else{
				s2[++len2]=b[i];
				c2[len2]=h[i];
			}
		}	
	}
	reverse(s2+1,s2+len2+1);
	reverse(c2+1,c2+len2+1);
	ll ans=0;
//	F(i,1,len1) cout<<s1[i]<<' '<<c1[i]<<endl;
//	cout<<endl;
//	F(i,1,len2) cout<<s2[i]<<' '<<c2[i]<<endl;
	for(int i=1,j=1;i<=len1,j<=len2;){
		if(c1[i]!=c2[j]) ans+=min(s1[i],s2[j]);
		if(s1[i]>s2[j]){
			s1[i]-=s2[j];
			j++;
		}else if(s1[i]<s2[j]){
			s2[j]-=s1[i];
			i++;
		}else{
			i++;
			j++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*7
5 a
3 c
6 b
12 c
3 c
12 a
2 d
*/
