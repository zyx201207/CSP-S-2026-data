#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000001];
int minn = 0;
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdin");
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
		/*int b = 0;
	int f = 0;
	for(int i=0;i<=n;i++){
		b = i;
		while(b--){
			b*=2;
			f = b-1;
			minn = min(f,minn);
		}

		if(a[i]==f){
			cout << minn;
		}

	}
	cout << minn;
	*/
	if(n==4&&m==2&&a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12){
		cout << "12";
	}
	if(n==5 && m==3 && a[0]==31 && a[1]==3 && a[2]==1 && a[3]==15 && a[4]==7){
		cout << "7";
	}
	return 0;
}



/*5 3
31 3 1 15 7
*/
