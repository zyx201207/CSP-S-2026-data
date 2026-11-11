//GZ-J00001 贵阳市实验三中 夏上云
#include <iostream>
using namespace std;

const int N = 5e5 + 5;
int a[N];
bool da[11];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int cnt = 0;
	for(int k = 1;k <= n;k++)
	{
		cin >> a[k];
		for(int i = k;i <= n;i++){
			if(da[a[i]] == 1){
				for(int j = 1;j <= i-1;i++){
					a[j] = a[j+i];
					a[j+i] = 0;
				}
				da[a[i]] = 0;
			}
			else{
				da[a[i]] = 1;
			}
		}
		for(int i = 1;i <= n;i++){
			if(a[i] != 0) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
