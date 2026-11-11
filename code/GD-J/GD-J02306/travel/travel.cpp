#include <iostream> 
using namespace std;
int main()
{
	string R1,R2,X1,X2,a,b;
	char c,d;
	cin>>R1>>R2>>X1>>X2; 
	if (R1==X1)cout<<1;
	else cout<<0;
	for(int i=0;i<=1;i++){
		a[i]=R2[i];
	}
	for(int i=0;i<=1;i++){
		b[i]=X2[i];
	}
	if (a==b)cout<<1;
	else cout<<0;
	c=R2[2];
	d=X2[2];
	//
	if ('A'<=c&&'C'>=c&&'A'<=d&&'C'>=d)cout<<1;
	else if ('D'<=c&&'F'>=c&&'D'<=d&&'F'>=d)cout<<1;
	else cout<<0;
	//
	if ('A'<=c&&'C'>=c&&'A'<=d&&'C'>=d)cout<<1;
	else if (('D'<=c&&'F'>=c&&'D'<=d&&'F'>=d)&&(d==c-1||d==c+1))cout<<1;
	else cout<<0;
	
	return 0;
}
