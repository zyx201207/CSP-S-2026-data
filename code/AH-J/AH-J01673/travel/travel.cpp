#include<bits/stdc++.h>
using namespace std;
string b,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,c; int num1,num2;
	cin>>a;
	num1=(a[0]-'0')*10+(a[1]-'0');
	cin>>b;
	cin>>c;
	num2=(c[0]-'0')*10+(c[1]-'0');
	cin>>d;
	if(a==c) 
		cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	    int ans1=(b[0]-'0')*10+(b[1]-'0'),ans2=(d[0]-'0')*10+(d[1]-'0');
	    if(ans1==ans2) cout<<1;
	    else 
		{
			cout<<"000"<<endl;
			return 0;
		}
	    int seat_1=int(b[2]-'A'),seat_2=int(d[2]-'A'),seat_3=int(b[2]-'A');
	    if(seat_1>seat_2) seat_1=seat_2,seat_2=seat_3;
	    //cout<<endl<<seat_1<<" "<<seat_2;
	    if((seat_1+1==seat_2)&&(!(seat_1==2&&seat_2==3))) 
	    	cout<<"11"<<endl;
	    	else
	    {
	    	if((seat_1<=2&&seat_2<=2)||(seat_1>=3&&seat_2>=3))
	    	cout<<"10"<<endl;
	    	else
	    	cout<<"00"<<endl;
		}
		
	return 0;
}
