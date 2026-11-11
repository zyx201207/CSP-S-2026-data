#include<bits/stdc++.h>
using namespace std;
long long n,s=1;
long long a[1000000010];
char c[100010];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>n;
	for(long long i=1;i<=n;i++){
		cin >>a[i]>>c[i];
		for(long long j=s;j<=a[i];j++){
			b[j]=c[i];
		}
		s+=a[i];
    }
	long long ch=b.size();
	if(ch%2!=0){
		long long d=0,zh=b[ch/2+1],q=1;
		for(long long i=ch/2+1;i<=ch;i++){
			if(b[i]!=b[zh-q]){
				d++;
			}
			q++;
		}
		cout <<d;
		return 0;
	}
	else{
		int d2=0,q2=0;
		for(long long i=ch/2+1;i<=ch;i++){
			if(b[i]!=b[ch/2-q2]){
				d2++;
			}
			q2++;
		}
		cout <<d2;
		return 0;
	}
	return 0;
}
