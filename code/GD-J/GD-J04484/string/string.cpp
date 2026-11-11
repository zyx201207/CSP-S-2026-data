#include <bits/stdc++.h>
using namespace std;

const int N=2e5+9; 
long long a[N+5];char c[N+5];
long long len;
long long cnt;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n; cin >> n;
	for(int i=1;i<=n;i++){
		int k; char p;
		cin >> k >> p;
		a[i]=k+a[i-1]; c[i]=p;
		len+=k;
	}//for(int i=1;i<=n;i++) cout << a[i]<<" ";
	//cout << endl;
	char q1,q2;
	//cout << len << endl;
	for(int i=1;i<=ceil(len/2);i++){
		int j=1;
		while(i>a[j]){
			j++;
		}
		q1 = c[j];//cout << j <<" ";
		j=1;
		while(len+1-i>a[j]){
			j++;
		}
		q2 = c[j];//cout <<j<<endl;;
		//cout << q1 << " " << q2<<endl;
		if(q1!=q2) cnt++;
	}
	cout << cnt;
}//2 3 a 2 a 1 c
