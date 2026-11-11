 #include<bits/stdc++.h>
 using namespace std;

 int main()
 {
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int g=0;
	int a[5]{};
	if(c1==c2) cout<<1;
	else {
	cout<<0;
	g=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&g==0) cout<<1;
	else cout<<0;
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&(s1[2]<'D'&&s2[2]<'D')&&g==0) cout<<1;
	else cout<<0;
	a[1]=s1[0]*10+s1[1];
	a[2]=s2[0]*10+s2[1];
	a[3]=s1[2];
	a[4]=s2[2];
	if(g==0){
		if(abs(a[1]-a[2])==1&&abs(a[3]-a[4])==0&&((a[3]>'D'&&a[4]>'D')||(a[3]<'D'&&a[4]<'D')))
		{
			cout<<1;
		}
		else if(abs(a[1]-a[2])==0&&abs(a[3]-a[4])==1&&((a[3]>'D'&&a[4]>'D')||(a[3]<'D'&&a[4]<'D')))
		cout<<1;
		else cout<<0;
	}
	else cout<<0;
    return 0;
 }
