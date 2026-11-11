#include<bits/stdc++.h>
#define rint long long
using namespace std;
const int N=2e5+10,inf=0x3f3f3f3f;
struct node{
    rint num;
    char c;
}a[N];
rint len;
rint ans;
rint up[N];
rint down[N];
int f(string s){
    string s1;
    int num=0;
    for(int i=0;i<s.length()/2;i++)s1+=s[i];
    for(int i=s.length()-1,j=0;i>s.length()/2;i--,j++)
        if(s1[j]!=s[i])
            num++;
    return num;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

    rint n;
    cin>>n;
    rint maxx=-inf;
    for(rint i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
        len+=a[i].num;
        maxx=max(maxx,a[i].num);
    }

    //68pts
    if(n<=2e5 and maxx<=500){
        string s;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=a[i].num;j++)
                s+=a[i].c;
        cout<<f(s);
        return 0;
    }


    rint half=len/2;
    if(len%2==1)half++;
	rint tsum=0;
	rint hid=0;
	for(int i=1;i<=n;i++){
		tsum+=a[i].num;
		if(tsum>=half){
			hid=i;
			break;
		}
	}
	if(tsum>half)
		a[hid].num-=(tsum-half);
	if(hid%2==0){
		for(int i=1;i<=hid;i++)
			up[a[i].c-'a'+1]+=a[i].num;
		for(int i=hid+1;i<=n;i++)
			down[a[i].c-'a'+1]+=a[i].num;
	}
	else{
		for(int i=1;i<hid;i++)
			up[a[i].c-'a'+1]+=a[i].num;
		for(int i=hid+1;i<=n;i++)
			down[a[i].c-'a'+1]+=a[i].num;
	}
    //cout<<half<<" "<<tsum;cout<<down[i]<<" ";
	for(int i=1;i<=26;i++){
        int num=min(up[i],down[i]);
        up[i]-=num;
        down[i]-=num;
	}
    for(int i=1;i<=26;i++)ans+=down[i];
    cout<<ans;
	return 0;
}

