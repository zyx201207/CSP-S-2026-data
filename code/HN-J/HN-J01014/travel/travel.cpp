#include<bits/stdc++.h>
using namespace std;
struct qwq{
	long long n;
	char x[10];
}a[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld%s",&a[1].n,&a[1].x);
	scanf("%lld%s",&a[2].n,&a[2].x);
	if(a[1].n==a[2].n) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(a[1].x[0]==a[1].x[0]&&a[1].x[1]==a[1].x[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(a[1].x[2]=='A'&&a[2].x[2]=='B'){
		cout<<"11";
		return 0;
	}
	if(a[1].x[2]=='A'&&a[2].x[2]=='C'){
		cout<<"10";
		return 0;
	}
	if(a[1].x[2]=='A'&&a[2].x[2]=='D'){
		cout<<"00";
		return 0;
	}
	if(a[1].x[2]=='A'&&a[2].x[2]=='F'){
		cout<<"00";
		return 0;
	}
	if(a[1].x[2]=='B'&&a[2].x[2]=='A'){
		cout<<"11";
		return 0;
	}
	if(a[1].x[2]=='B'&&a[2].x[2]=='C'){
		cout<<"11";
		return 0;
	}
	if(a[1].x[2]=='B'&&a[2].x[2]=='D'){
		cout<<"00";
		return 0;
	}
	if(a[1].x[2]=='B'&&a[2].x[2]=='F'){
		cout<<"00";
		return 0;
	}
	if(a[1].x[2]=='C'&&a[2].x[2]=='A'){
		cout<<"10";
		return 0;
	}
	if(a[1].x[2]=='C'&&a[2].x[2]=='B'){
		cout<<"11";
		return 0;
	}
	if(a[1].x[2]=='C'&&a[2].x[2]=='D'){
		cout<<"00";
		return 0;
	}
	if(a[1].x[2]=='C'&&a[2].x[2]=='F'){
		cout<<"00";
		return 0;
	}
	if(a[1].x[2]=='D'&&a[2].x[2]=='A'){
		cout<<"11";
		return 0;
	}
	if(a[1].x[2]=='D'&&a[2].x[2]=='B'){
		cout<<"00";
		return 0;
	}
	if(a[1].x[2]=='D'&&a[2].x[2]=='C'){
		cout<<"00";
		return 0;
	}
	if(a[1].x[2]=='D'&&a[2].x[2]=='F'){
		cout<<"11";
		return 0;
	}
	if(a[1].x[2]=='F'&&a[2].x[2]=='A'){
		cout<<"00";
		return 0;
	}
	if(a[1].x[2]=='F'&&a[2].x[2]=='B'){
		cout<<"00";
		return 0;
	}
	if(a[1].x[2]=='F'&&a[2].x[2]=='C'){
		cout<<"00";
		return 0;
	}
	if(a[1].x[2]=='F'&&a[2].x[2]=='D'){
		cout<<"11";
		return 0;
	}
	return 0;
}
