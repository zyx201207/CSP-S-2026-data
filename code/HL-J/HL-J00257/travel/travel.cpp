#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    double s1,s2;
    cin >>c1>>s1>>c2>>s2;

    if(c1=c2){
		cout<<1;
		if((int)s1/100==(int)s2/100){
			cout<<1;
			for(int i=0;i<=100;i++){
				if((int)s1-(int)s1/100=='A'&&(int)s2-(int)s2/100=='B')
					cout <<1;
				else if((int)s1-(int)s1/100=='A'&&(int)s2-(int)s2/100=='C')
					cout <<1;
				else if((int)s1-(int)s1/100=='B'&&(int)s2-(int)s2/100=='C')
					cout <<1;
				else if((int)s1-(int)s1/100=='C'&&(int)s2-(int)s2/100=='B'||(int)s2-(int)s2/100=='A')
					cout <<1;
				else if((int)s1-(int)s1/100=='D'&&(int)s2-(int)s2/100=='E')
					cout <<1;
				else	cout <<0<<0;
			if((int)s1-(int)s1/100=='A'&&(int)s2-(int)s2/100=='B')
				cout <<1;
			else if((int)s1-(int)s1/100=='B'&&(int)s2-(int)s2/100=='C')
				cout <<1;
			else if((int)s1-(int)s1/100=='D'&&(int)s2-(int)s2/100=='F')
				cout <<1;
			else
				cout <<0;
			}

		}
    	else cout <<0<<0<<0;
	}
    else{
		cout <<0<<0<<0<<0;
	}
}

