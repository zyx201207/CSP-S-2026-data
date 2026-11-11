#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
    int bq1=0,bq2=0,bq3=0,bq4=0;
	if(c1==c2)bq1=1;
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&bq1)bq2=1;
    int n1,n2;
    char sc1=s1[2],sc2=s2[2];
    if(sc1=='A'||sc1=='B'||sc1=='C')n1=1;
    else n1=2;
    if(sc2=='A'||sc2=='B'||sc2=='C')n2=1;
    else n2=2;
    if(n1==n2&&bq1&&bq2)bq3=1;
    if(bq1&&bq2&&bq3&&((sc1=='A'&&sc2=='B')||(sc1=='B'&&sc2=='A')||(sc1=='C'&&sc2=='B')||(sc1=='B'&&sc2=='C')||(sc1=='D'&&sc2=='F')||(sc1=='F'&&sc2=='D')))bq4=1;
    cout<<bq1<<bq2<<bq3<<bq4;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
