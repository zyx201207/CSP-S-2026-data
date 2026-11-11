#include<bits/stdc++.h>
using namespace std;
string q;
struct stu{
	long long sx;
	long long az;
	char we;
};
stu a[10010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	int op = 0;
	for(int i = 1;i<=n;i++){
		long long s;
		char d;
		cin>>s>>d;
		op = op+s;
		a[i].sx = op;
		a[i].az = s;
		a[i].we = d;
	}
	int o= 0;
	for(int i = 0;i<q.size()/2;i++){
		if(q[i]!=q[q.size()-1-i])o++;
	}
	cout<<o;

	fclose(stdin);
	fclose(stdout);
} 
