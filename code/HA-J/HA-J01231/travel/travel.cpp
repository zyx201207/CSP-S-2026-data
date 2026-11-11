#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1=="01A")
			if(s2=="01B")cout<<1<<1<<1;
			else if(s2=="01C")cout<<1<<1<<0;
			else if(s2=="01D" || s2=="01F")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="01B")
			if(s2=="01A" || s2=="01C")cout<<1<<1<<1;
			else if(s2=="01D" || s2=="01F")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="01C")
			if(s2=="01B")cout<<1<<1<<1;
			else if(s2=="01A")cout<<1<<1<<0;
			else if(s2=="01D" || s2=="01F")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="01D")
			if(s2=="01F")cout<<1<<1<<1;
			else if(s2=="01A" || s2=="01B" || s2=="01C")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="01F")
			if(s2=="01E")cout<<1<<1<<1;
			else if(s2=="01A" || s2=="01B" || s2=="01C")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		
		else if(s1=="05A")
			if(s2=="05B")cout<<1<<1<<1;
			else if(s2=="05C")cout<<1<<1<<0;
			else if(s2=="05D" || s2=="05F")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="05B")
			if(s2=="05A" || s2=="05C")cout<<1<<1<<1;
			else if(s2=="05D" || s2=="05F")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="05C")
			if(s2=="05B")cout<<1<<1<<1;
			else if(s2=="05A")cout<<1<<1<<0;
			else if(s2=="05D" || s2=="5F")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="05D")
			if(s2=="05F")cout<<1<<1<<1;
			else if(s2=="05A" || s2=="05B" || s2=="05C")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="05F")
			if(s2=="05E")cout<<1<<1<<1;
			else if(s2=="05A" || s2=="05B" || s2=="05C")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		
		else if(s1=="10A")
			if(s2=="10B")cout<<1<<1<<1;
			else if(s2=="10C")cout<<1<<1<<0;
			else if(s2=="10D" || s2=="10F")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="10B")
			if(s2=="10A" || s2=="10C")cout<<1<<1<<1;
			else if(s2=="10D" || s2=="10F")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="10C")
			if(s2=="10B")cout<<1<<1<<1;
			else if(s2=="10A")cout<<1<<1<<0;
			else if(s2=="10D" || s2=="10F")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="10D")
			if(s2=="10F")cout<<1<<1<<1;
			else if(s2=="10A" || s2=="10B" || s2=="10C")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="10F")
			if(s2=="10E")cout<<1<<1<<1;
			else if(s2=="10A" || s2=="10B" || s2=="10C")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		
		else if(s1=="14A")
			if(s2=="14B")cout<<1<<1<<1;
			else if(s2=="14C")cout<<1<<1<<0;
			else if(s2=="14D" || s2=="14F")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="14B")
			if(s2=="14A" || s2=="14C")cout<<1<<1<<1;
			else if(s2=="14D" || s2=="14F")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="14C")
			if(s2=="14B")cout<<1<<1<<1;
			else if(s2=="14A")cout<<1<<1<<0;
			else if(s2=="14D" || s2=="14F")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="14D")
			if(s2=="14F")cout<<1<<1<<1;
			else if(s2=="14A" || s2=="14B" || s2=="14C")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else if(s1=="14F")
			if(s2=="14E")cout<<1<<1<<1;
			else if(s2=="14A" || s2=="14B" || s2=="14C")cout<<1<<0<<0;
			else cout<<0<<0<<0;
		else cout<<0<<0<<0;	
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
