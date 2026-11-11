#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	char p1a,p1b,m1,m2,m3,p2a,p2b,n1,n2,n3,df1=0,df2=0;
	cin >> p1a >> p1b >> m1 >> m2 >> m3 >> p2a >> p2b >> n1 >> n2 >> n3;
	if(p1a==p2a&&p1b==p2b){
		cout << '1';
		if(m1==n1&&m2==n2){
			cout << '1';
			if(m3=='A'||m3=='B'||m3=='C'){
				df1++;
			}
			if(n3=='A'||n3=='B'||n3=='C'){
				df1++;
			}
			if(m3=='D'||m3=='F'){
				df2++;
			}
			if(n3=='D'||n3=='F'){
				df2++;
			}
			if(df2==2||df1==2){
				cout << '1';
				if(df1==2){
					if(m3=='A'&&n3=='C'){
						cout << '0';
					}else if(m3=='C'&&n3=='A'){
						cout << '0';
					}else{
						cout << '1';
					}
				}else{
					cout << '1';
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
