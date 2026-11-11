#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
long long a[200005]; 
bool cmp(long long a,long long b){
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	long long me=-114;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		me = max(me,a[i]);
	}
	sort(a,a+n,cmp);
	long long mx=0,mq=a[0];
	//for(int i=0;i<n;i++)cout<<a[i];
	if(m==1)cout<<a[0];
	if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				if(i!=j)mx=max(mx,a[i]&a[j]);
		}
		cout<<mx;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}if(m==n){
		for(int i=1;i<n;i++)mq &= a[i];
		cout<<mq;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}if(me<=4){
		bool stt3=false,stt1=false,edd3=false,edd1=false,h4=false,h2=false;
		int mn=m,st3=-1,st1=-1,ed1=-1,ed3=-1,cn4=0,cn2=0;
		for(int i=0;i<n;i++)
		{
			if(i==3 && !stt3)st3=i,stt3=true;
			if(i!=3 && stt3 && !edd3)ed3=i,edd3=true;
			if(i==1 && !stt1)st1=i,stt1=true;
			if(i!=1 && stt1 && !edd1)ed1=i,edd1=true;
			if(a[i]==4)cn4++,h4=true;
			if(a[i]==2)cn2++,h2=true;
		}
		if(stt3&&!edd3)edd3=true,ed3=n-1; 
		if(stt1&&!edd1)edd1=true,ed1=n-1;
		if(!stt3&&!stt1){
			if(cn4>=m)
			{
				cout<<4;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}else if(cn2>=m)
			{
				cout<<2;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}else
			{
				cout<<0;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
		if(stt3)
		{
			if(ed3-st3+1>=m)
			{
				cout<<3;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}else if(ed3-st3+1+cn2>=m)
			{
				cout<<2;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}else if(ed3-st3+1+cn2>=m)
			{
				cout<<1;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}else cout<<0;
		}
	}
	cout<< 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
