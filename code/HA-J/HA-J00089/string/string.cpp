#include <bits/stdc++.h>
using namespace std;
struct t{
	int x;
	char y;
};
t a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=1,cnt=0;
	cin >> n;
	long long k=n;
	for(int i=1;i<=n;i++){
		cin >> a[i].x >> a[i].y;
	}
	while(s!=k){
		if(a[s].y==a[k].y){
			if(a[s].x>=a[k].x){
				a[s].x-=a[k].x;
				k--;
			}
			else{
				a[k].x-=a[s].x;
				s++;
			}
		}
		else{
			if(a[s].x>=a[k].x){
				a[s].x-=a[k].x;
				cnt+=a[k].x;
				k--;
			}
			else{
				a[k].x-=a[s].x;
				cnt+=a[s].x;
				s++;
			}
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
