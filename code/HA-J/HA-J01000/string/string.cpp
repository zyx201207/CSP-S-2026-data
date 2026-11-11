#include<bits/stdc++.h>
using namespace std;
int n,r;
long long m,cnt;
char z;
vector<long long>a;
vector<char>b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n;
    bool f=true;
    for(int i=0;i<n;i++){
    	long long x;
    	char y;cin>>x>>y;
    	a.push_back(x);b.push_back(y);
    	if(b[0]!=b[i])f=false;
	}
	if(f){
		cout<<0;
		return 0;
	}m=a[0];r=n;
	for(int i=1;i<=n;i++){
	    for(int j=r;j>=i;j--){
	    	if(b[i]!=b[j]){
			    if(m>=a[j]){
			        cnt+=m-a[j];
			        m-=a[j];
			        r--;
			    }
			    else if(m<a[j]&&m>0){
				    cnt+=a[j]-m;
				    m-=a[j];
				    break;
				    }
				else if(m<a[j]&&m<=0){
				    cnt+=a[j]-m;
				    m-=a[j];
				    break;
				    }
			}
		}
	}
	return 0;
}
