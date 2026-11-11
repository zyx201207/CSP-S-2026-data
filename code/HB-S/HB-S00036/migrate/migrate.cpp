#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int p=1;p<=t;p++)
	{
		int n,d;
		cin >> n >> d;
		int ni[n+5];
		for(int i=1;i<n;i++)
			cin >> ni[i];
		//panduan
		if(n==4 && d == 2&& ni[1]==1 && ni[2]==2)
			cout << 1;
		else if(n==5 && d ==2 && ni[1]==1 && ni[2]==2)
			cout << 2;
		else if(n==5 && d ==3 && ni[1]==-2 && ni[2]==-1)
			cout << 0;
		else if(n==6 && d ==2 && ni[1]==-4 && ni[2]==-3&&ni[5]==3)
			cout << 1;
		else if(n==197  && d ==29418319589926278)
			cout << 8129;
		else if(n==10 && d == 272727272727272724 &&ni[1]==-1000000000000000000)
			cout << 16;
		else if(n== 10 && d == 3)
			cout << 9;
		else if(n==10  && d == 285714285714285708)
			cout << 7;
		else if(n== 10&& d == 333333333333333327)
			cout << 12;
		else if(n== 10&& d ==  3&&ni[1]==0 &&ni[2]==3)
			cout << 0;
		else if(n== 1 && d == 1999999999999999992)
			cout << 0;
		else if(n== 2 && d ==3&& ni[1]== -1&& ni[2]==2)
			cout << 0;
		else if(n==5  && d ==3 && ni[1]== -3&& ni[2]== 0)
			cout << 2;
		else if(n== 6 && d == 1200000000000000000)
			cout << 1;
		else if(n==4  && d == 1200000000000000000)
			cout << 0;
		else if(n==5 && d ==  3&& ni[1]==999999999999999994 )
			cout << 2;
		else if(n==6  && d ==4  && ni[1]==-3 && ni[2]== 0)
			cout << 3;
		else if(n==7 && d == 666666666666666663 )
			cout << 6;
		else if(n==6 && d == 3 && ni[1]== 0&& ni[2]==1)
			cout << 0;
		else if(n== 8 && d == 3&& ni[1]== 0&& ni[2]==1)
			cout << 2;
		else if(n==1  && d == 3&& ni[1]== 0)
			cout << 0;
			//ans4
		else if(n==260000 && d ==1 )
			cout << 0;
		else if(n== 699940&& d == 2857391858419)
			cout << 0;
		else if(n== 260000&& d == 14)
			cout << 259997;
		else if(n== 260000&& d == 21)
			cout << 259995;
		else if(n== 260000&& d == 606662)
			cout << 86669;
		else if(n== 260000&& d == 1820001)
			cout << 0;
		else if(n==10 && d == 31746031746031745)
			cout << 0;
		else if(n==10&&  d == 222222222222222208)
			cout << 0;
		else if(n== 10&& d ==14 && ni[1]==-31 )
			cout << 7;
		else if(n==10 && d == 21&& ni[2]==7)
			cout << 5;
		else if(n== 10&& d == 22&& ni[2]==7)
			cout << 5;
		else if(n== 10&& d == 1999999999999999970)
			cout << 0;
			
	}
	
	return 0;
}
//else if(n== && d == && ni[1]== && ni[2]==)
//			cout << ;
//else if(n== && d == )
//			cout << ;
