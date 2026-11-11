#include <iostream>
using namespace std;
const int N =200001;
const int M =200001;
long long a[N],s[M];
int f(int x,int y)
{
	int b[31]={0},c[31]={0},tel_b,tel_c,tel,ans[31],wer=0;
	tel_b=0;
	while(x>0){
		tel_b++;
		b[tel_b]=x%2;
	}
	tel_c=0;
	while(y>0){
		tel_c++;
		b[tel_c]=x%2;
	}
	if(tel_c>tel_b) tel=tel_c;
	else tel=tel_b;
	int m=1;
	for(int i=1;i<=tel;i++){
		if(b[i]==c[i]) ans[i]=1;
		else ans[i]=0;
		wer+=ans[i]*m;
		m*=2;
	}
	return wer;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,p,max;
	max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s[1]=1;
	p=1;
	while(p>=0){
		if(p==m){
			if(s[p]<=n){
				int total=f(a[s[1]],a[s[2]]);
				for(int i=3;i<=m;i++) total=f(total,a[s[i]]);				
				if(total>max) max=total;
			}
			else{
			   s[p]=s[p-1]+1;
			   p--;
			}
		}
		else{
			s[p+1]=s[p];
			p++;
		}
		s[p]++;
	}
	cout<<max;
	return 0;
}
		
