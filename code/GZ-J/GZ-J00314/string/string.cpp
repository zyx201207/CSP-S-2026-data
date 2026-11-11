//GZ-J00314   陈彧山 	遵义市新蒲新区滨湖中学 
#include <bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
long long sum,tail;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		cin >> c[i];
	}
	int i = 1;
	tail = n;
	while( tail - i>= 1){
		if(a[i] >= a[tail]){
			while(a[i] >= a[tail]){
				if(c[i] == c[tail]){
		
				}else{
					sum+=a[tail];
				}
				a[i]-=a[tail];
				tail--;
			}
		}else{
			while(a[i] <= a[tail]){
				if(c[i] == c[tail]){
		
				}else{
					sum+=a[i];
				}
				a[tail]-=a[i];
				i++;
			}
			i--;
		}
		
	}
	
	cout << sum;
	return 0;
}

