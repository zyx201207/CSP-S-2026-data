#include <iostream>
#include <cstring>

using namespace std;

long long n;
long long a[200005];
string b[200005];
long long ans=0;

int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin.tie();
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cin >> b[i];
	}
	
	int l=1;
	int r=n;
	while(l<r){
		if(b[l]==b[r]){
			
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
				
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			
		}
		else if(b[l]!=b[r]){
			if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}
			else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
				
			}
			else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
	}
	
	cout << ans;
	return 0;
}
