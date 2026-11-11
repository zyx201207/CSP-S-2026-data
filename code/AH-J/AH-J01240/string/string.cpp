 #include<bits/stdc++.h>
 using namespace std;
 struct str{
	 long long nu;
	 char c;
 };
 int main()
 {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0;
	cin>>n;
	str a[200000];
	for(long long i=0;i<n;i++)
		cin>>a[i].nu>>a[i].c;
	long long l=0,r=n-1;
	while(l<=r)
	{
		long long k=min(a[l].nu,a[r].nu);
		if(a[l].c!=a[r].c)
			s+=k;
		a[l].nu-=k;
		a[r].nu-=k;
		if(a[l].nu<=0)
			l++;
		if(a[r].nu<=0)
			r--;
	}
	cout<<s;
	return 0;
}
