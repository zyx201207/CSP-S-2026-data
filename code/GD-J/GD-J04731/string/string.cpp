#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,a[N],b[N],ans,w1,w2;
char c1[N],c2[N];
bool v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c1[i];
		b[n-i+1]=a[i];
		c2[n-i+1]=c1[i];
	}
	w2=b[1];
	int j=1;
	for(int i=1;i<=n;i++){
		if(w1+a[i]<w2){
			if(c1[i]!=c2[j])
				ans+=a[i];
			w1+=a[i];
			continue;
		}
		if(c1[i]!=c2[j])
		    ans+=w2-w1;
		w1+=a[i];
		j++;
		while(w2+b[j]<w1){
			if(c2[j]!=c1[i])
			    ans+=b[j];
			w2+=b[j];
			j++;
		}
		if(c2[j]!=c1[i])
		    ans+=w1-w2;
		w2+=b[j];
	}
	cout<<ans/2;
	return 0;
} 
