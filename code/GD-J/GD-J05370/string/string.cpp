#include<iostream>
using namespace std;

//  n < 2*10^5  ai < 10^9

int n,c[200000];
long long a[200000],s=0,len=0;// s=修改个数 

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	char ch;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i]>>ch,
		len+=a[i],
		c[i]=ch-'a';
	
	long long l=0,r=0,lt=0,rt=0,lw,rw;
	while(lt+a[l]<=len/2||rt+a[n-r-1]<=len/2){
		lw=lt+a[l];  // 区间 lt ~ lw-1 
		rw=rt+a[n-r-1];
		if(c[l]!=c[n-r-1])
			s+=min(lw,rw)-max(lt,rt);
		if(lw>=rw)
			r++,rt=rw;
		else
			l++,lt=lw;
	}
	cout<<s;
	return 0;
}
