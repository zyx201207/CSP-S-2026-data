#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200050];
char c[200050];
long long minn=1e12+5,maxx=0;
int ans;
bool b=true;
long long d[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=n;
	for(int i=1;i<=sum;i++){
		cin>>a[i]>>c[i];
		if(a[i]!=1){
			b=false;
		}
	}
	if(b){
		for(int i=1;i<=sum/2;i++){
			if(c[i]!=c[n-i+1]){
				ans++;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	int s=0;
        for(int i=1;i<=sum;i++){
                if(i=1||c[i]!=c[i-1]){
			s++;
		}
		d[s]+=a[i];
        }
	for(int i=1;i<=sum;i++){
                minn=min(minn,d[i]);
                maxx=max(maxx,d[i]);
	}
	if(sum==1){
		cout<<"0\n";
		return 0;
	}
	if(sum==2){
		cout<<minn<<'\n';
		return 0;
	}
	cout<<maxx<<'\n';
	return 0;
}
