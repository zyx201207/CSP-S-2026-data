#include <bits/stdc++.h>

using namespace std;

struct num{
	int onenum;
	int x;
};

bool b(num c,num y){
	if(c.onenum>y.onenum){
		return true;
	}
	else if(c.onenum==y.onenum){
		if(c.x>y.x){
			return true;
		}
		return false;
	}
	return false;
}

int main(){
	freopen("and.in.txt","r",stdin);
	freopen("and.out.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	num a[200005];
	for(int i=0;i<n;i++){			//100000
		cin>>a[i].x;
		a[i].onenum=0;
		int temp=a[i].x;
		while(temp>0){					//30
			if(temp%2){
				a[i].onenum++;
			}
			temp/=2;
		}
	}
	sort(a,a+n,b);
	cout<<a[m-1].x;
	fclose(stdin);
	fclose(stdout);
}
