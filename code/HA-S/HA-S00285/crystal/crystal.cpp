#include <bits/stdc++.h>

using namespace std;
const int N=5e6+10;
const long long _MAX=1e17+10;
const long long _MIN=-1e17-10;
long long a,b,_min=_MAX,_max=_MIN;
long long n[N],x[N],ans=0,c=0,__max=_MIN;
long long aaa(int x){
	for(int i=a;i>=1;i--){
		if(n[i]==x){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> a >> b;
	for(long long i=1;i<=a;i++){
		cin >> n[i];
		_max=max(_max,n[i]);
		_min=min(_min,n[i]);
	}
	sort(n+1,n+a+1);
	for(long long i=_min+1;i<=_max;i++){
		c=0;
		ans=0;
		for(long long j=aaa(i);j>=1;j--){
			if(n[j]==i){
				ans++;
			}else{
				if((i-n[j]+c)>b){
					break;
				}else{
					c+=i-n[j];
					ans++;
				}
			}
		}
		x[i]=ans;
		__max=max(__max,x[i]);
	}
	cout << __max;
}
//Oct31==Dec25? 
