//string
//??? a[i]<=1e9 真的可以丢这么多字符进去吗
//考虑题目性质 s[i]=s[L+1-i];
//这样可以?
//两个小时做不出来
#include<iostream>
using namespace std;
// string s;
long long n;
struct s{
	char le;
	long long ti;
	long long start;
};
s a[210000];
// long long i=1;
long long sum=0;
long long t=0;
long long read(){
	long long f=1;
	long long res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		int kk=ch-48;
		res=res*10+kk;
		ch=getchar();
	}
	return res*f;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)print(x/10);
	putchar(x%10+48);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	// s.clear();
	n=read();
	int idx=0;
	char prele='!';
	for(long long i=1;i<=n;i++){
		long long ti1;char le;
		ti1=read();
		cin>>le;
		if(prele==le){
			a[idx].ti+=ti1;
			prele=le;
		}
		else{
			idx++;
			a[idx].ti=ti1;
			a[idx].le=le;
			a[idx].start=0;
			// idx++;
			prele=le;
		}
		sum+=ti1;
	}
	// idx--;
	// cout<<idx;
	// for(long long i=1;i<=idx;i++){
	// 	cout<<a[i].le<<" ";
	// }
	// long long idx=1;
	long long i,j;
	int ff=0;
	for(i=1,j=idx;i<=(idx+1)/2,j>(idx+1)/2;i++,j--){
			// cout<<i<<" "<<j<<endl;
			if(ff==1){
				ff=0;
				i--;
			}
			if(ff==2){
				ff=0;j++;
			}
			if(a[i].ti-a[i].start==a[j].ti-a[j].start&&a[i].le!=a[j].le){
				a[i].le=a[j].le;
				// cout<<a[i].ti<<" "<<a[i].le;
				t+=a[i].ti;
			}//如果首尾两段长度相同 字母不同
			else if(a[i].le!=a[j].le&&a[i].ti!=a[j].ti){
				if(a[i].ti>a[j].ti){
					a[j].le=a[i].le;
					t+=a[j].ti;
					a[i].start+=a[j].ti;
					ff=1;
				}
				else if(a[i].ti<a[j].ti){
					a[i].le=a[j].le;
					t+=a[i].ti;
					a[j].start+=a[i].ti;
					ff=2;
				}
			}
	}
	print(t);
}
