#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300001],k,len,p=0,ans=0;
char c[200001],l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	c[0]='0';
	len=n;
	for(int i=1;i<=n;i++){
		cin>>k>>l;
		if(c[i-p-1]==l){//如果与前面相同就合并 
			a[i-p-1]+=k;
			p++;
			len--;
		}else{//否则单开一项 
			a[i-p]=k;
			c[i-p]=l;
		}
	}
	p=1;
	len++;
	while(len-p!=p){
		if(c[p]==c[len-p]){//如果本来就是回文就不需要ans++， 
			if(a[p]>a[len-p]){//比较大小 
				a[p]=a[p]-a[len-p];//跳至前（后）一项 
				len--;//右边长度-- 
				
			}else{
			
				a[len-p]=a[len-p]-a[p];
				p++;
				if(a[len-p]==0){
					len--;
				}
			}
		}else{
			if(a[p]>a[len-p]){//相同，只不过要加ans 
				a[p]=a[p]-a[len-p];
				ans+=a[len-p];
				len--;
			}else{
				a[len-p]=a[len-p]-a[p];
				ans+=a[p];
				p++;
				if(a[len-p]==0){
					len--;
				}
			}
			
			p++;
			
		}
		
	}
	cout<<ans;//输出 
}
