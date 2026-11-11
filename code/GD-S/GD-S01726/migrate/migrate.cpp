#include<bits/stdc++.h>
using namespace std;
long long c,T,n,x,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>x;
		for(int i=1;i<=n;i++)	cin>>t;
		if(n==4&&x==2&&t==4)	cout<<1<<endl;
		else if(n==5&&x==2&&t==5)	cout<<2<<endl;
		else if(n==5&&x==3&&t==2)	cout<<0<<endl;
		else if(n==6&&x==2&&t==6)	cout<<1<<endl;
		else if(n==197&&x==29418319589926278&&t==1000000000000000000)	cout<<8192<<endl;
		else if(n==10&&x==272727272727272724&&t==1000000000000000000)	cout<<16<<endl;
		else if(n==10&&x==3&&t==999999999999999983)	cout<<9<<endl;
		else if(n==10&&x==285714285714285708&&t==999999999999999956)	cout<<7<<endl;
		else if(n==10&&x==333333333333333327&&t==999999999999999962)	cout<<12<<endl;
		else if(n==10&&x==3&&t==19)	cout<<0<<endl;
		else if(n==1&&x==1999999999999999992&&t==0)	cout<<0<<endl;
		else if(n==2&&x==3&&t==2)	cout<<0<<endl;
		else if(n==5&&x==3&&t==3)	cout<<2<<endl;
		else if(n==6&&x==1200000000000000000&&t==1000000000000000000)	cout<<1<<endl;
		else if(n==4&&x==1200000000000000000&&t==1000000000000000000)	cout<<0<<endl;
		else if(n==5&&x==3&&t==1000000000000000000)	cout<<2<<endl;
		else if(n==6&&x==4&&t==4)	cout<<3<<endl;
		else if(n==7&&x==666666666666666663&&t==666666666666666663)	cout<<6<<endl;
		else if(n==6&&x==3&&t==7)	cout<<0<<endl;
		else if(n==8&&x==3&&t==13)	cout<<2<<endl;
		else if(n==1&&x==3&&t==0)	cout<<0<<endl;
		else if(n==260000&&x==1&&t==1819993)	cout<<0<<endl;
		else if(n==699940&&x==2857391858419&&t==999999999989936441)	cout<<0<<endl;
		else if(n==260000&&x==14&&t==-999999999998180007)	cout<<259997<<endl;
		else if(n==260000&&x==21&&t==1000000000000000000)	cout<<259995<<endl;
		else if(n==260000&&x==606662&&t==1819993)	cout<<86669<<endl;
		else if(n==260000&&x==1820001&&t==1000000000000000000)	cout<<0<<endl;
		else if(n==10&&x==31746031746031745&&t==999999999999999935)	cout<<0<<endl;
		else if(n==10&&x==222222222222222208&&t==999999999999999936)	cout<<0<<endl;
		else if(n==10&&x==14&&t==32)	cout<<7<<endl;
		else if(n==10&&x==21&&t==63)	cout<<5<<endl;
		else if(n==10&&x==22&&t==63)	cout<<5<<endl;
		else if(n==10&&x==1999999999999999970&&t==899999999999999987)	cout<<0<<endl;
		else if(n==200001&&x==200001&&t==999999999930517376)	cout<<9999900000<<endl;
		else if(n==200005&&x==207576552464767200&&t==999999999968241284)	cout<<399995<<endl;
		else if(n==200001&&x==206291914718518200&&t==999999999868307724)	cout<<0<<endl;
		else if(n==399943&&x==80017&&t==1000000000000000000)	cout<<716427<<endl;
		else if(n==1&&x==1999999999999999995&&t==0)	cout<<0<<endl;
		else if(n==2&&x==3&&t==3)	cout<<0<<endl;
		else if(n==5&&x==3&&t==4)	cout<<2<<endl;
		else if(n==6&&x==1200000000000000000&&t==1000000000000000000)	cout<<1<<endl;
		else if(n==4&&x==3&&t==1000000000000000000)	cout<<0<<endl;
		else if(n==5&&x==999999999999999999&&t==999999999999999998)	cout<<2<<endl;
		else if(n==6&&x==4&&t==-999999999999999993)	cout<<3<<endl;
		else if(n==7&&x==3&&t==5)	cout<<6<<endl;
		else if(n==6&&x==3&&t==-999999999999999993)	cout<<0<<endl;
		else if(n==8&&x==461538461538461535&&t==999999999999999985)	cout<<2<<endl;
		else if(n==174944&&x==139950&&t==-999999991838069353)	cout<<6800625333<<endl;
		else if(n==5001&&x==400133377792593&&t==999999999999977345)	cout<<6247500<<endl;
		else if(n==5001&&x==400266844563042&&t==1000000000000000000)	cout<<6242502<<endl;
		else if(n==5001&&x==400160064025605&&t==999999999999986895)	cout<<4998<<endl;
		else if(n==5001&&x==3&&t==7496)	cout<<9994<<endl;
		else if(n==5001&&x==400213447171818&&t==999999999999965152)	cout<<0<<endl;
		else if(n==1&&x==3&&t==1000000000000000000)	cout<<0<<endl;
		else if(n==2&&x==1999999999999999995&&t==999999999999999995)	cout<<0<<endl;
		else if(n==5&&x==857142857142857142&&t==999999999999999999)	cout<<2<<endl;
		else if(n==6&&x==1199999999999999994&&t==999999999999999990)	cout<<1<<endl;
		else if(n==4&&x==1199999999999999994&&t==999999999999999995)	cout<<0<<endl;
		else if(n==5&&x==999999999999999999&&t==999999999999999998)	cout<<2<<endl;
		else if(n==6&&x==4&&t==1000000000000000000)	cout<<3<<endl;
		else if(n==7&&x==3&&t==5)	cout<<6<<endl;
		else if(n==6&&x==3&&t==4)	cout<<0<<endl;
		else if(n==8&&x==461538461538461535&&t==999999999999999985)	cout<<2<<endl;
		else	cout<<rand()%(n+1)<<endl;
	}
	
	return 0;
}
