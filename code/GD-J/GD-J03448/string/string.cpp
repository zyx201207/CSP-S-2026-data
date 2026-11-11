#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
//	cout << n; //test
	string a,b;
	long long num;
	char ch;
	for(int i=0; i<n; i++){
		cin >> num >> ch;
//		cout << num << " " << ch << endl; //test
		for(long long j=0; j<num; j++){
			a=a+ch;
			b=ch+b;
		}
	}
//	cout << a << endl << b; //test
	long long ans=0;
	for(long long i=0; i<a.size(); i++){
		if(a[i]!=b[i]) ans++;
	}
	printf("%lld\n",ans/2);
	fclose(stdout);
	fclose(stdin);
	return 0;
}
