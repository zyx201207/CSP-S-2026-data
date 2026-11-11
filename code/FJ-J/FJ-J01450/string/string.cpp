#include<bits/stdc++.h>
using namespace std;
long long n,c[10000000],a[88888888];
char r;
stack <long long> s;
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=n;i>0;i--){
		cin >> c[i];
		cin >> r;
		a[i]=r;
		if(i%2!=0&&i==n/2+1){
			
		}else{
			s.push(r);
			if(s.top()==s.top()-1){
				s.pop();;
				s.pop();;
				i-=2;
			}
		}
	}
	cout << s.size();
	return 0;
}
