#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

vector<pair<char,char>> seat={{'A','B'},{'B','C'},{'C','D'},{'D','F'}};

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;

    bool a1=0,a2=0,a3=0,a4=0;

    a1=(c1==c2);
    if(a1) {
        a2=(s1.substr(0,2)==s2.substr(0,2));
        if(a2) {
            a3=((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s2[2]=='D'||s2[2]=='F')&&(s1[2]=='D'||s1[2]=='F'));
            if(a3) {
                for(int i=0;i<4;i++) {
                    pair<char,char> sseat=seat[i];
                    a4=(s1[2]==sseat.x&&s2[2]==sseat.y)||(s1[2]==sseat.y&&s2[2]==sseat.x);
                    if(a4) break;
                }
            }
        }
    }

    cout<<a1<<a2<<a3<<a4;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
