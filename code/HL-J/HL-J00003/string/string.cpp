#include<iostream>
#include<string>
using namespace std;
const int N=1e9+2;
long long x2=0,length;
long long n,cnt;char ch[N],cx;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		long long x;
		cin>>x;
		cin>>cx;
		for(long long j=x2;j<=x2+x;j++){
			ch[j]=cx;
		}
		x2+=x;
		length=x2;
	}
	if(length%2==0){
		long long b=length/2;
		for(long long i=0;i<b;i++){
			if(ch[i]!=ch[length-i-1]){
				cnt++;
			}
		}
		cout<<cnt;
	}else{
		long long b=length/2;
		for(long long i=0;i<b;i++){
			if(ch[i]!=ch[length-i-1]){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}