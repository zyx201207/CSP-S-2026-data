#include<bits/stdc++.h>
using namespace std;
char a1,a2,s1,s2,s3,d1,d2,f1,f2,f3;
bool q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>s1>>s2>>s3>>d1>>d2>>f1>>f2>>f3;
	
	if (a1==d1 and a2==d2){
		cout<<"1";
		if (s1==f1 and s2==f2){
			cout<<"1";
			if ((s3=='D' and f3=='F') or(s3=='F' and f3=='D')or (s3=='A' and f3=='B')or (s3=='B' and f3=='A')or (s3=='A' and f3=='C')or (s3=='C'and f3=='A') or(s3=='B' and f3=='C')or(s3=='C' and f3=='B')){
				cout<<"1";
				if ((s3=='D' and f3=='F') or(s3=='F' and f3=='D')or (s3=='A' and f3=='B')or (s3=='B' and f3=='A')or(s3=='B' and f3=='C')or(s3=='C' and f3=='B')){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
