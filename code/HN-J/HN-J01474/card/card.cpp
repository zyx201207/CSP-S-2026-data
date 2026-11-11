#include<iostream>
#include<stack>
const int N = 3e5+10;
const int M = 5e5+10;
using namespace std;
stack<long long>q;
long long n,m;
int ct[N];
int a[M];
bool b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		//cout << i << endl;
		for(int j = i;j <= n;j++){
			if(a[j] != a[j+1]||j == n){
				ct[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ct[i] << ' ';
	}
	return 0;
}
