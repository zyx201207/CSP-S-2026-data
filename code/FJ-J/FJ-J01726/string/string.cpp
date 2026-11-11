#include<bits/stdc++.h>
using namespace std;
long long a[200005],cnt,n,w=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		w+=a[i];
    }
	long long tw=0,t=0;
	long long tw2=0,t2=n+1;
	while(tw<w/2){
		t++;
		while(tw2<tw+a[t]){
			t2--;
			tw2+=a[t2];
			if(tw2<=tw+a[t]&&c[t2]!=c[t])cnt+=a[t2];
			else if(c[t2]!=c[t]){
				cnt+=a[t2];
				if(tw2==w/2+1&&w%2==1)cnt--;
			}
		}
		tw+=a[t];
	}
	cout<<cnt;
}
