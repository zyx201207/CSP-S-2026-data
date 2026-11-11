#include<bits/stdc++.h>
using namespace std;
int n,m,c=31,ans;
int a[200005];
int b[99];
int ex[99];
//容易发现，按位与的数不会变大只会变小，即a&b=c,c<=a,b
//因此，选取策略就是使答案一位为1，并且使得选取的m个数此位为1
//重复上述过程直到选出m个数为止，当然要保证选取的1位尽量高 
//粗略估算O(n),常数30 
int mypow(int b,int e){
	int re=1;
	for(int i=1;i<=e;i++)
		re*=b;
	return re;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=30;i++)
		ex[i]=mypow(2,i);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],k=0;
		while(x){
			b[k]+=x%2;
			x/=2;
			k++;
		}
	}
	while(n>m){
		for(int i=c-1;i>=0;i--){
			if(b[i]>=m){
				c=i;
				break;
			}
			if(i==0)
				c=-1;
		}
		if(c==-1)
			break;
		int v=b[c];		
		for(int i=0;i<=30;i++){
//			cout<<b[i]<<' ';
			b[i]=0;			
		}
//		cout<<"\n"<<c<<'\n';
		for(int i=1;i<=n;i++){
			if((a[i]&ex[c])==0)
				a[i]=0;
			else{
				int x=a[i],k=0;
				while(x){
					b[k]+=x%2;
					x/=2;
					k++;
				}		
			}
		}
		sort(a+1,a+1+n,cmp);
		n=v;
		if(c==0)
			break;
	}
	for(int i=1;i<=n;i++){
		if(i>1)
			a[i]=(a[i]&a[i-1]);
	}
	ans=a[n];
	cout<<ans;
	return 0;
}
