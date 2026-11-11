#include<bits/stdc++.h>
using namespace std;
int n;
long long s;
struct qp{
	long long nu;
	char zi;
}a[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].nu >> a[i].zi;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].zi==a[r].zi){
			if(a[l].nu>a[r].nu){
				a[l].nu-=a[r].nu;
				r--;
			}else if(a[l].nu==a[r].nu){
				l++;
				r--;
			}else{
				a[r].nu-=a[l].nu;
				l++;
			}
		}else{
			if(a[l].nu>a[r].nu){
				s+=a[r].nu;
				a[l].nu-=a[r].nu;
				r--;
			}else if(a[l].nu==a[r].nu){
				s+=a[r].nu;
				l++;
				r--;
			}else{
				s+=a[l].nu;
				a[r].nu-=a[l].nu;
				l++;
			}			
		}
	}
	cout << s;
	return 0;
}

