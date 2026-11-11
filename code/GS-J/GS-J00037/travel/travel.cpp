#include <bits/stdc++.h>
using namespace std;
string a[23]={"01A","02A","03A","04A","05A","06A","07A","08A","09A","10A","11A","12A","13A","14A","15A","16A","17A","18A"};
string b[23]={"01B","02B","03B","04B","05B","06B","07B","08B","09B","10B","11B","12B","13B","14B","15B","16B","17B","18B"};
string c[23]={"01C","02C","03C","04C","05C","06C","07C","08C","09C","10C","11C","12C","13C","14C","15C","16C","17C","18C"};
string d[23]={"01D","02D","03D","04D","05D","06D","07D","08D","09D","10D","11D","12D","13D","14D","15D","16D","17D","18D"};
string f[23]={"01F","02F","03F","04F","05F","06F","07F","08F","09F","10F","11F","12F","13F","14F","15F","16F","17F","18F"};
string g[10]={"01A","01B","01C","01D","01F"};
string h[10]={"02A","02B","02C","02D","02F"};
string y[10]={"03A","03B","03C","03D","03F"};
string j[10]={"04A","04B","04C","04D","04F"};
string k[10]={"05A","05B","05C","05D","05F"};
string l[10]={"06A","06B","06C","06D","06F"};
string m[10]={"07A","07B","07C","07D","07F"};
string n[10]={"08A","08B","08C","08D","08F"};
string o[10]={"09A","09B","09C","09D","09F"};
string p[10]={"10A","10B","10C","10D","10F"};
string q[10]={"11A","11B","11C","11D","11F"};
string r[10]={"12A","12B","12C","12D","12F"};
string s[10]={"13A","13B","13C","13D","13F"};
string t[10]={"14A","14B","14C","14D","14F"};
string u[10]={"15A","15B","15C","15D","15F"};
string v[10]={"16A","16B","16C","16D","16F"};
string w[10]={"17A","17B","17C","17D","17F"};
string z[10]={"18A","18B","18C","18D","18F"};
string answer1;
string answer2;
string answer3;
string answer4;
int cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,cnt6=0,cnt7=0,cnt8=0,cnt9=0,cnt10=0,cnt11=0,cnt12=0,cnt13=0,cnt14=0,cnt15=0,cnt16=0,cnt17=0,cnt18=0,cnt19=0,cnt20=0,cnt21=0,cnt22=0,cnt23=0,cnt24=0,cnt25=0,cnt26=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>answer1>>answer2>>answer3>>answer4;
	if(answer1==answer3){
		cout<<"1"<<" ";
	}
	else{
		cout<<"0"<<" ";
	}
	for(int x=0;x<18;x++){
		if(g[x]==answer2){
			cnt8++;
		}
		if(g[x]==answer4){
			cnt8++;
		}
		if(cnt8==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(h[x]==answer2){
			cnt9++;
		}
		if(h[x]==answer4){
			cnt9++;
		}
		if(cnt9==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(y[x]==answer2){
			cnt10++;
		}
		if(y[x]==answer4){
			cnt10++;
		}
		if(cnt10==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(j[x]==answer2){
			cnt11++;
		}
		if(j[x]==answer4){
			cnt11++;
		}
		if(cnt11==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(k[x]==answer2){
			cnt12++;
		}
		if(k[x]==answer4){
			cnt12++;
		}
		if(cnt12==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(l[x]==answer2){
			cnt13++;
		}
		if(l[x]==answer4){
			cnt13++;
		}
		if(cnt13==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(m[x]==answer2){
			cnt14++;
		}
		if(m[x]==answer4){
			cnt14++;
		}
		if(cnt14==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(n[x]==answer2){
			cnt15++;
		}
		if(n[x]==answer4){
			cnt15++;
		}
		if(cnt15==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(o[x]==answer2){
			cnt16++;
		}
		if(o[x]==answer4){
			cnt16++;
		}
		if(cnt16==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(p[x]==answer2){
			cnt17++;
		}
		if(p[x]==answer4){
			cnt17++;
		}
		if(cnt17==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(q[x]==answer2){
			cnt18++;
		}
		if(q[x]==answer4){
			cnt18++;
		}
		if(cnt18==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(r[x]==answer2){
			cnt19++;
		}
		if(r[x]==answer4){
			cnt19++;
		}
		if(cnt19==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(s[x]==answer2){
			cnt20++;
		}
		if(s[x]==answer4){
			cnt20++;
		}
		if(cnt20==2){
			cout<<"1"<<" ";
			break;
		}
		if(t[x]==answer2){
			cnt21++;
		}
		if(t[x]==answer4){
			cnt21++;
		}
		if(cnt21==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(u[x]==answer2){
			cnt22++;
		}
		if(u[x]==answer4){
			cnt22++;
		}
		if(cnt22==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(v[x]==answer2){
			cnt23++;
		}
		if(v[x]==answer4){
			cnt23++;
		}
		if(cnt23==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(w[x]==answer2){
			cnt24++;
		}
		if(w[x]==answer4){
			cnt24++;
		}
		if(cnt24==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
		if(z[x]==answer2){
			cnt25++;
		}
		if(z[x]==answer4){
			cnt25++;
		}
		if(cnt25==2){
			cout<<"1"<<" ";
			cnt26++;
			break;
		}
	}
	for(int i=0;i<18;i++){
		if(a[i]==answer2){
			cnt1++;
		}
		if(a[i]==answer4){
			cnt1++;
		}
		if(cnt1==2){
			cnt6++;
			break;
		}
		if(b[i]==answer2){
			cnt2++;
		}
		if(b[i]==answer4){
			cnt2++;
		}
		if(cnt2==2){
			cnt6++;
			break;
		}
		if(c[i]==answer2){
			cnt3++;
		}
		if(c[i]==answer4){
			cnt3++;
		}
		if(cnt3==2){
			cnt6++;
			break;
		}
		if(d[i]==answer2){
			cnt4++;
		}
		if(d[i]==answer4){
			cnt4++;
		}
		if(cnt4==2){
			cnt7++;
			break;
		}
		if(f[i]==answer2){
			cnt5++;
		}
		if(f[i]==answer4){
			cnt5++;
		}
		if(cnt5==2){
			cnt7++;
			break;
		}
	}
		cout<<"0"<<" ";
	for(int i=0;i<18;i++){
		if(answer2==a[i]&&answer4==b[i]){
			cout<<"1"<<" ";
			break;
		}
		else if(answer2==b[i]&&answer4==c[i]){
			cout<<"1"<<" ";
			break;
		}
		else if(answer2==d[i]&&answer4==f[i]){
			cout<<"1"<<" ";
			break;
		}
		if(i==17){
			cout<<"0"<<" ";
			break;
		}
	}
	return 0;
}
