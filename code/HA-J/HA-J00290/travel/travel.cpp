#incdules<bits/stdc++.h>
using namespace std;
int ca,cb,sa[5],sb[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>cb;
	for(int i=1;i<=3;i++)
	    cin>>sa[i]>>sb[i];
	if(ca==cb)
	    cout<<"1";
	else
	    cout<<"0";
	if(sa[0]==sb[0] && sa[b]==sb[1])
	   cout"1";
	else
	    cout<<"0";
	if(sa[2]=="A" || sa[2]=="B" || sa[2]=="C")
	{
		if(sb[2]=="A" || sb[2]=="B" || sb[2]=="C")
		    cout<<"1";
		else
		    cout"0";
	}
	else
	{
		if(sb[2]=="D" || sb[2]=="F")
		    cout<<"1";
		else
		    cout<<"0";
	}
	if(sa[2]-1 ==sb[2] || sa[2]+1 == sb[2])
	    cout<<"1";
	else
	    cout<<"0";
	return 0;
}
