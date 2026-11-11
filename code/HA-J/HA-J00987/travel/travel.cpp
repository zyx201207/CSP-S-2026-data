 #include <bits/stdc++.h>
 using namespace std;
 string n,m,s,t;
 string u = "0",p = "0",y = "0", r = "0";
 int main(){
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	cin >> n >> m >> s >> t;
 	if(n==s){
 		u = "1";
 	}
 	cout << u + p + y + r;
 	return 0;
 }
