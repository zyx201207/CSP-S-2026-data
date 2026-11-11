#include<bits/stdc++.h>
using namespace std;
long long a[100002],n,b=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
    	long long d;
    	char c;
    	cin>>d>>c;
    	s[i]=c;
    	a[i]=d;
    }
    int x=1,y=n;
    for(int i=1;x<y;i++){
    	if(s[x]!=s[y]){
    		if(a[x]<a[y]){
    			ans+=a[x];
    			a[y]-=a[x];
    			x++;
			}
			else if(a[x]>a[y]){
				ans+=a[y];
				a[x]-=a[y];
				y--;
			}
    		else if(a[x]==a[y]){
    			ans+=a[x];
    			x++;
    			y--;
			}
		}
		else{
			if(a[x]<a[y]){
    			a[y]-=a[x];
    			x++;
			}
			else if(a[x]>a[y]){
				a[x]-=a[y];
				y--;
			}
    		else if(a[x]==a[y]){
    			x++;
    			y--;
			}
		}
	}
	cout<<ans;
}
