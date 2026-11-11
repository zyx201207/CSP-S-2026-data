//GZ-S00265 观山湖中学 吴昆灿
#include<bits/stdc++.h>
using namespace std;
long long m,n,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int a[n+5],max=-1,h;
	for(int i=0;i<n;i++){
		cin >> a[i]; 
	}
	sort(a,a+n);
	
	for(int i=0;i<=m;i++){
		for(int j=0;j<=i;j++){
			int t=j,p=i;
			while(t>=0){
				if(p>n-1){
					p=0;
				}
				a[p]++;
				t--;
				p++;
			}
			int num=0,d=0;
			for(int k=0;k<n;k++){
				if(a[d]==a[k]){
					num++;
				}
			}
			if(num > max){
				swap(num,max);
				h=j;
			}
		}
	}
	cout << max+1;
	return 0;
}
