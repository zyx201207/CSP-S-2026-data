#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	string cjy1,sjy1,cjy2,sjy2;
	cin>>cjy1>>sjy1>>cjy2>>sjy2;
	if(cjy1==cjy2){
		cout<<1;
		if(sjy1=="01A"&&sjy2=="01B"){
			cout<<111;
		}
		else if(sjy1=="01A"&&sjy2=="01C"){
			cout<<110;
		}
		else if(sjy1=="01A"&&sjy2=="01D"){
			cout<<100;
		}
	else if(sjy1=="01A"&&sjy2=="01F"){
		cout<<100;
	}//1line
	else if(sjy1=="01B"&&sjy2=="01A"){
		cout<<111;
	}
	else if(sjy1=="01B"&&sjy2=="01C"){
		cout<<111;
	}
	else if(sjy1=="01B"&&sjy2=="01D"){
		cout<<100;
	}
	else if(sjy1=="01B"&&sjy2=="01F"){
		cout<<100;
	}//2line
	else if(sjy1=="01C"&&sjy2=="01A"){
		cout<<110;
	}
	else if(sjy1=="01C"&&sjy2=="01B"){
		cout<<111;
	}
	else if(sjy1=="01C"&&sjy2=="01D"){
		cout<<100;
	}
	else if(sjy1=="01C"&&sjy2=="01F"){
		cout<<100;
	}//3line
	else if(sjy1=="01D"&&sjy2=="01A"){
		cout<<100;
	}
	else if(sjy1=="01D"&&sjy2=="01C"){
		cout<<100;
	}
	else if(sjy1=="01D"&&sjy2=="01B"){
		cout<<100;
	}
	else if(sjy1=="01D"&&sjy2=="01F"){
		cout<<111;
	}//4line
	else if(sjy1=="01F"&&sjy2=="01A"){
		cout<<100;
	}
	else if(sjy1=="01F"&&sjy2=="01C"){
		cout<<100;
	}
	else if(sjy1=="01F"&&sjy2=="01D"){
		cout<<111;
	}
	else if(sjy1=="01F"&&sjy2=="01B"){
		cout<<100;
	}//5line    first cross
	else if(sjy1=="02A"&&sjy2=="02B"){
		cout<<111;
	}
	else if(sjy1=="02A"&&sjy2=="02C"){
		cout<<110;
	}
	else if(sjy1=="02A"&&sjy2=="02D"){
		cout<<100;
	}
	else if(sjy1=="02A"&&sjy2=="02F"){
		cout<<100;
	}//1line
	else if(sjy1=="02B"&&sjy2=="02A"){
		cout<<111;
	}
	else if(sjy1=="02B"&&sjy2=="02C"){
		cout<<111;
	}
	else if(sjy1=="02B"&&sjy2=="02D"){
		cout<<100;
	}
	else if(sjy1=="02B"&&sjy2=="02F"){
		cout<<100;
	}//2line
	else if(sjy1=="02C"&&sjy2=="02A"){
		cout<<110;
	}
	else if(sjy1=="02C"&&sjy2=="02B"){
		cout<<111;
	}
	else if(sjy1=="02C"&&sjy2=="02D"){
		cout<<100;
	}
	else if(sjy1=="02C"&&sjy2=="02F"){
		cout<<100;
	}//3line
	else if(sjy1=="02D"&&sjy2=="02A"){
		cout<<100;
	}
	else if(sjy1=="02D"&&sjy2=="02C"){
		cout<<100;
	}
	else if(sjy1=="02D"&&sjy2=="02B"){
		cout<<100;
	}
	else if(sjy1=="02D"&&sjy2=="02F"){
		cout<<111;
	}//4line
	else if(sjy1=="02F"&&sjy2=="02A"){
		cout<<100;
	}
	else if(sjy1=="02F"&&sjy2=="02C"){
		cout<<100;
	}
	else if(sjy1=="02F"&&sjy2=="02D"){
		cout<<111;
	}
	else if(sjy1=="02F"&&sjy2=="02B"){
		cout<<100;
	}//5line    second cross
	else if(sjy1=="03A"&&sjy2=="03B"){
		cout<<111;
	}
	else if(sjy1=="03A"&&sjy2=="03C"){
		cout<<110;
	}
	else if(sjy1=="03A"&&sjy2=="03D"){
		cout<<100;
	}
	else if(sjy1=="03A"&&sjy2=="03F"){
		cout<<100;
	}//1line
	else if(sjy1=="03B"&&sjy2=="03A"){
		cout<<111;
	}
	else if(sjy1=="03B"&&sjy2=="03C"){
		cout<<111;
	}
	else if(sjy1=="03B"&&sjy2=="03D"){
		cout<<100;
	}
	else if(sjy1=="03B"&&sjy2=="03F"){
		cout<<100;
	}//2line
	else if(sjy1=="03C"&&sjy2=="03A"){
		cout<<110;
	}
	else if(sjy1=="03C"&&sjy2=="03B"){
		cout<<111;
	}
	else if(sjy1=="03C"&&sjy2=="03D"){
		cout<<100;
	}
	else if(sjy1=="03C"&&sjy2=="03F"){
		cout<<100;
	}//3line
	else if(sjy1=="03D"&&sjy2=="03A"){
		cout<<100;
	}
	else if(sjy1=="03D"&&sjy2=="03C"){
		cout<<100;
	}
	else if(sjy1=="03D"&&sjy2=="03B"){
		cout<<100;
	}
	else if(sjy1=="03D"&&sjy2=="03F"){
		cout<<111;
	}//4line
	else if(sjy1=="03F"&&sjy2=="03A"){
		cout<<100;
	}
	else if(sjy1=="03F"&&sjy2=="03C"){
		cout<<100;
	}
	else if(sjy1=="03F"&&sjy2=="03D"){
		cout<<111;
	}
	else if(sjy1=="03F"&&sjy2=="03B"){
		cout<<100;
	}//5line    third cross
	else if(sjy1=="04A"&&sjy2=="04B"){
		cout<<111;
	}
	else if(sjy1=="04A"&&sjy2=="04C"){
		cout<<110;
	}
	else if(sjy1=="04A"&&sjy2=="04D"){
		cout<<100;
	}
	else if(sjy1=="04A"&&sjy2=="04F"){
		cout<<100;
	}//1line
	else if(sjy1=="04B"&&sjy2=="04A"){
		cout<<111;
	}
	else if(sjy1=="04B"&&sjy2=="04C"){
		cout<<111;
	}
	else if(sjy1=="04B"&&sjy2=="04D"){
		cout<<100;
	}
	else if(sjy1=="04B"&&sjy2=="04F"){
		cout<<100;
	}//2line
	else if(sjy1=="04C"&&sjy2=="04A"){
		cout<<110;
	}
	else if(sjy1=="04C"&&sjy2=="04B"){
		cout<<111;
	}
	else if(sjy1=="04C"&&sjy2=="04D"){
		cout<<100;
	}
	else if(sjy1=="04C"&&sjy2=="04F"){
		cout<<100;
	}//3line
	else if(sjy1=="04D"&&sjy2=="04A"){
		cout<<100;
	}
	else if(sjy1=="04D"&&sjy2=="04C"){
		cout<<100;
	}
	else if(sjy1=="04D"&&sjy2=="04B"){
		cout<<100;
	}
	else if(sjy1=="04D"&&sjy2=="04F"){
		cout<<111;
	}//4line
	else if(sjy1=="04F"&&sjy2=="04A"){
		cout<<100;
	}
	else if(sjy1=="04F"&&sjy2=="04C"){
		cout<<100;
	}
	else if(sjy1=="04F"&&sjy2=="04D"){
		cout<<111;
	}
	else if(sjy1=="04F"&&sjy2=="04B"){
		cout<<100;
	}//5line    forth cross
	else if(sjy1=="05A"&&sjy2=="05B"){
		cout<<111;
	}
	else if(sjy1=="05A"&&sjy2=="05C"){
		cout<<110;
	}
	else if(sjy1=="05A"&&sjy2=="05D"){
		cout<<100;
	}
	else if(sjy1=="05A"&&sjy2=="05F"){
		cout<<100;
	}//1line
	else if(sjy1=="05B"&&sjy2=="05A"){
		cout<<111;
	}
	else if(sjy1=="05B"&&sjy2=="05C"){
		cout<<111;
	}
	else if(sjy1=="05B"&&sjy2=="05D"){
		cout<<100;
	}
	else if(sjy1=="05B"&&sjy2=="05F"){
		cout<<100;
	}//2line
	else if(sjy1=="05C"&&sjy2=="05A"){
		cout<<110;
	}
	else if(sjy1=="05C"&&sjy2=="05B"){
		cout<<111;
	}
	else if(sjy1=="05C"&&sjy2=="05D"){
		cout<<100;
	}
	else if(sjy1=="05C"&&sjy2=="05F"){
		cout<<100;
	}//3line
	else if(sjy1=="05D"&&sjy2=="05A"){
		cout<<100;
	}
	else if(sjy1=="05D"&&sjy2=="05C"){
		cout<<100;
	}
	else if(sjy1=="05D"&&sjy2=="05B"){
		cout<<100;
	}
	else if(sjy1=="05D"&&sjy2=="05F"){
		cout<<111;
	}//4line
	else if(sjy1=="05F"&&sjy2=="05A"){
		cout<<100;
	}
	else if(sjy1=="05F"&&sjy2=="05C"){
		cout<<100;
	}
	else if(sjy1=="05F"&&sjy2=="05D"){
		cout<<111;
	}
	else if(sjy1=="05F"&&sjy2=="05B"){
		cout<<100;
	}//5line    fifth cross
	else if(sjy1=="06A"&&sjy2=="06B"){
		cout<<111;
	}
	else if(sjy1=="06A"&&sjy2=="06C"){
		cout<<110;
	}
	else if(sjy1=="06A"&&sjy2=="06D"){
		cout<<100;
	}
	else if(sjy1=="06A"&&sjy2=="06F"){
		cout<<100;
	}//1line
	else if(sjy1=="06B"&&sjy2=="06A"){
		cout<<111;
	}
	else if(sjy1=="06B"&&sjy2=="06C"){
		cout<<111;
	}
	else if(sjy1=="06B"&&sjy2=="06D"){
		cout<<100;
	}
	else if(sjy1=="06B"&&sjy2=="06F"){
		cout<<100;
	}//2line
	else if(sjy1=="06C"&&sjy2=="06A"){
		cout<<110;
	}
	else if(sjy1=="06C"&&sjy2=="06B"){
		cout<<111;
	}
	else if(sjy1=="06C"&&sjy2=="06D"){
		cout<<100;
	}
	else if(sjy1=="06C"&&sjy2=="06F"){
		cout<<100;
	}//3line
	else if(sjy1=="06D"&&sjy2=="06A"){
		cout<<100;
	}
	else if(sjy1=="06D"&&sjy2=="06C"){
		cout<<100;
	}
	else if(sjy1=="06D"&&sjy2=="06B"){
		cout<<100;
	}
	else if(sjy1=="06D"&&sjy2=="06F"){
		cout<<111;
	}//4line
	else if(sjy1=="06F"&&sjy2=="06A"){
		cout<<100;
	}
	else if(sjy1=="06F"&&sjy2=="06C"){
		cout<<100;
	}
	else if(sjy1=="06F"&&sjy2=="06D"){
		cout<<111;
	}
	else if(sjy1=="06F"&&sjy2=="06B"){
		cout<<100;
	}//5line    sixth cross
	else if(sjy1=="07A"&&sjy2=="07B"){
		cout<<111;
	}
	else if(sjy1=="07A"&&sjy2=="07C"){
		cout<<110;
	}
	else if(sjy1=="07A"&&sjy2=="07D"){
		cout<<100;
	}
	else if(sjy1=="07A"&&sjy2=="07F"){
		cout<<100;
	}//1line
	else if(sjy1=="07B"&&sjy2=="07A"){
		cout<<111;
	}
	else if(sjy1=="07B"&&sjy2=="07C"){
		cout<<111;
	}
	else if(sjy1=="07B"&&sjy2=="07D"){
		cout<<100;
	}
	else if(sjy1=="07B"&&sjy2=="07F"){
		cout<<100;
	}//2line
	else if(sjy1=="07C"&&sjy2=="07A"){
		cout<<110;
	}
	else if(sjy1=="07C"&&sjy2=="07B"){
		cout<<111;
	}
	else if(sjy1=="07C"&&sjy2=="07D"){
		cout<<100;
	}
	else if(sjy1=="07C"&&sjy2=="07F"){
		cout<<100;
	}//3line
	else if(sjy1=="07D"&&sjy2=="07A"){
		cout<<100;
	}
	else if(sjy1=="07D"&&sjy2=="07C"){
		cout<<100;
	}
	else if(sjy1=="07D"&&sjy2=="07B"){
		cout<<100;
	}
	else if(sjy1=="07D"&&sjy2=="07F"){
		cout<<111;
	}//4lin
	else if(sjy1=="07F"&&sjy2=="07A"){
		cout<<100;
	}
	else if(sjy1=="07F"&&sjy2=="07C"){
		cout<<100;
	}
	else if(sjy1=="07F"&&sjy2=="07D"){
		cout<<111;
	}
	else if(sjy1=="07F"&&sjy2=="07B"){
		cout<<100;
	}//5line    seventh cross
	else if(sjy1=="08A"&&sjy2=="08B"){
		cout<<111;
	}
	else if(sjy1=="08A"&&sjy2=="08C"){
		cout<<110;
	}
	else if(sjy1=="08A"&&sjy2=="08D"){
		cout<<100;
	}
	else if(sjy1=="08A"&&sjy2=="08F"){
		cout<<100;
	}//1line
	else if(sjy1=="08B"&&sjy2=="08A"){
		cout<<111;
	}
	else if(sjy1=="08B"&&sjy2=="08C"){
		cout<<111;
	}
	else if(sjy1=="08B"&&sjy2=="08D"){
		cout<<100;
	}
	else if(sjy1=="08B"&&sjy2=="08F"){
		cout<<100;
	}//2line
	else if(sjy1=="08C"&&sjy2=="08A"){
		cout<<110;
	}
	else if(sjy1=="08C"&&sjy2=="08B"){
		cout<<111;
	}
	else if(sjy1=="08C"&&sjy2=="08D"){
		cout<<100;
	}
	else if(sjy1=="08C"&&sjy2=="08F"){
		cout<<100;
	}//3line
	else if(sjy1=="08D"&&sjy2=="08A"){
		cout<<100;
	}
	else if(sjy1=="08D"&&sjy2=="08C"){
		cout<<100;
	}
	else if(sjy1=="08D"&&sjy2=="08B"){
		cout<<100;
	}
	else if(sjy1=="08D"&&sjy2=="08F"){
		cout<<111;
	}//4line
	else if(sjy1=="08F"&&sjy2=="08A"){
		cout<<100;
	}
	else if(sjy1=="08F"&&sjy2=="08C"){
		cout<<100;
	}
	else if(sjy1=="08F"&&sjy2=="08D"){
		cout<<111;
	}
	else if(sjy1=="08F"&&sjy2=="08B"){
		cout<<100;
	}//5line    eighth cross
	else if(sjy1=="09A"&&sjy2=="09B"){
		cout<<111;
	}
	else if(sjy1=="09A"&&sjy2=="09C"){
		cout<<110;
	}
	else if(sjy1=="09A"&&sjy2=="09D"){
		cout<<100;
	}
	else if(sjy1=="09A"&&sjy2=="09F"){
		cout<<100;
	}//1line
	else if(sjy1=="09B"&&sjy2=="09A"){
		cout<<111;
	}
	else if(sjy1=="09B"&&sjy2=="09C"){
		cout<<111;
	}
	else if(sjy1=="09B"&&sjy2=="09D"){
		cout<<100;
	}
	else if(sjy1=="09B"&&sjy2=="09F"){
		cout<<100;
	}//2line
	else if(sjy1=="09C"&&sjy2=="09A"){
		cout<<110;
	}
	else if(sjy1=="09C"&&sjy2=="09B"){
		cout<<111;
	}
	else if(sjy1=="09C"&&sjy2=="09D"){
		cout<<100;
	}
	else if(sjy1=="09C"&&sjy2=="09F"){
		cout<<100;
	}//3line
	else if(sjy1=="09D"&&sjy2=="09A"){
		cout<<100;
	}
	else if(sjy1=="09D"&&sjy2=="09C"){
		cout<<100;
	}
	else if(sjy1=="09D"&&sjy2=="09B"){
		cout<<100;
	}
	else if(sjy1=="09D"&&sjy2=="09F"){
		cout<<111;
	}//4line
	else if(sjy1=="09F"&&sjy2=="09A"){
		cout<<100;
	}
	else if(sjy1=="09F"&&sjy2=="09C"){
		cout<<100;
	}
	else if(sjy1=="09F"&&sjy2=="09D"){
		cout<<111;
	}
	else if(sjy1=="09F"&&sjy2=="09B"){
		cout<<100;
	}//5line    ninth cross
	else if(sjy1=="10A"&&sjy2=="10B"){
		cout<<111;
	}
	else if(sjy1=="10A"&&sjy2=="10C"){
		cout<<110;
	}
	else if(sjy1=="10A"&&sjy2=="10D"){
		cout<<100;
	}
	else if(sjy1=="10A"&&sjy2=="10F"){
		cout<<100;
	}//1line
	else if(sjy1=="10B"&&sjy2=="10A"){
		cout<<111;
	}
	else if(sjy1=="10B"&&sjy2=="10C"){
		cout<<111;
	}
	else if(sjy1=="10B"&&sjy2=="10D"){
		cout<<100;
	}
	else if(sjy1=="10B"&&sjy2=="10F"){
		cout<<100;
	}//2line
	else if(sjy1=="10C"&&sjy2=="10A"){
		cout<<110;
	}
	else if(sjy1=="10C"&&sjy2=="10B"){
		cout<<111;
	}
	else if(sjy1=="10C"&&sjy2=="10D"){
		cout<<100;
	}
	else if(sjy1=="10C"&&sjy2=="10F"){
		cout<<100;
	}//3line
	else if(sjy1=="10D"&&sjy2=="10A"){
		cout<<100;
	}
	else if(sjy1=="10D"&&sjy2=="10C"){
		cout<<100;
	}
	else if(sjy1=="10D"&&sjy2=="10B"){
		cout<<100;
	}
	else if(sjy1=="10D"&&sjy2=="10F"){
		cout<<111;
	}//4line
	else if(sjy1=="10F"&&sjy2=="10A"){
		cout<<100;
	}
	else if(sjy1=="10F"&&sjy2=="10C"){
		cout<<100;
	}
	else if(sjy1=="10F"&&sjy2=="10D"){
		cout<<111;
	}
	else if(sjy1=="10F"&&sjy2=="10B"){
		cout<<100;
	}//5line    tenth cross
	else if(sjy1=="11A"&&sjy2=="11B"){
		cout<<111;
	}
	else if(sjy1=="11A"&&sjy2=="11C"){
		cout<<110;
	}
	else if(sjy1=="11A"&&sjy2=="11D"){
		cout<<100;
	}
	else if(sjy1=="11A"&&sjy2=="11F"){
		cout<<100;
	}//1line
	else if(sjy1=="11B"&&sjy2=="11A"){
		cout<<111;
	}
	else if(sjy1=="11B"&&sjy2=="11C"){
		cout<<111;
	}
	else if(sjy1=="11B"&&sjy2=="11D"){
		cout<<100;
	}
	else if(sjy1=="11B"&&sjy2=="11F"){
		cout<<100;
	}//2line
	else if(sjy1=="11C"&&sjy2=="11A"){
		cout<<110;
	}
	else if(sjy1=="11C"&&sjy2=="11B"){
		cout<<111;
	}
	else if(sjy1=="11C"&&sjy2=="11D"){
		cout<<100;
	}
	else if(sjy1=="11C"&&sjy2=="11F"){
		cout<<100;
	}//3line
	else if(sjy1=="11D"&&sjy2=="11A"){
		cout<<100;
	}
	else if(sjy1=="11D"&&sjy2=="11C"){
		cout<<100;
	}
	else if(sjy1=="11D"&&sjy2=="11B"){
		cout<<100;
	}
	else if(sjy1=="11D"&&sjy2=="11F"){
		cout<<111;
	}//4line
	else if(sjy1=="11F"&&sjy2=="11A"){
		cout<<100;
	}
	else if(sjy1=="11F"&&sjy2=="11C"){
		cout<<100;
	}
	else if(sjy1=="11F"&&sjy2=="11D"){
		cout<<111;
	}
	else if(sjy1=="11F"&&sjy2=="11B"){
		cout<<100;
	}//5line    eleventh cross
	else if(sjy1=="12A"&&sjy2=="12B"){
		cout<<111;
	}
	else if(sjy1=="12A"&&sjy2=="12C"){
		cout<<110;
	}
	else if(sjy1=="12A"&&sjy2=="12D"){
		cout<<100;
	}
	else if(sjy1=="12A"&&sjy2=="12F"){
		cout<<100;
	}//1line
	else if(sjy1=="12B"&&sjy2=="12A"){
		cout<<111;
	}
	else if(sjy1=="12B"&&sjy2=="12C"){
		cout<<111;
	}
	else if(sjy1=="12B"&&sjy2=="12D"){
		cout<<100;
	}
	else if(sjy1=="12B"&&sjy2=="12F"){
		cout<<100;
	}//2line
	else if(sjy1=="12C"&&sjy2=="12A"){
		cout<<110;
	}
	else if(sjy1=="12C"&&sjy2=="12B"){
		cout<<111;
	}
	else if(sjy1=="12C"&&sjy2=="12D"){
		cout<<100;
	}
	else if(sjy1=="12C"&&sjy2=="12F"){
		cout<<100;
	}//3line
	else if(sjy1=="12D"&&sjy2=="12A"){
		cout<<100;
	}
	else if(sjy1=="12D"&&sjy2=="12C"){
		cout<<100;
	}
	else if(sjy1=="12D"&&sjy2=="12B"){
		cout<<100;
	}
	else if(sjy1=="12D"&&sjy2=="12F"){
		cout<<111;
	}//4line
	else if(sjy1=="12F"&&sjy2=="12A"){
		cout<<100;
	}
	else if(sjy1=="12F"&&sjy2=="12C"){
		cout<<100;
	}
	else if(sjy1=="12F"&&sjy2=="12D"){
		cout<<111;
	}
	else if(sjy1=="12F"&&sjy2=="12B"){
		cout<<100;
	}//5line    twelveth cross
		else if(sjy1=="13A"&&sjy2=="13B"){
			cout<<111;
		}
		else if(sjy1=="13A"&&sjy2=="13C"){
			cout<<110;
		}
		else if(sjy1=="13A"&&sjy2=="13D"){
			cout<<100;
		}
		else if(sjy1=="13A"&&sjy2=="13F"){
			cout<<100;
		}//1line
		else if(sjy1=="13B"&&sjy2=="13A"){
			cout<<111;
		}
		else if(sjy1=="13B"&&sjy2=="13C"){
			cout<<111;
		}
		else if(sjy1=="13B"&&sjy2=="13D"){
			cout<<100;
		}
		else if(sjy1=="13B"&&sjy2=="13F"){
			cout<<100;
		}//2line
		else if(sjy1=="13C"&&sjy2=="13A"){
			cout<<110;
		}
		else if(sjy1=="13C"&&sjy2=="13B"){
			cout<<111;
		}
		else if(sjy1=="13C"&&sjy2=="13D"){
			cout<<100;
		}
		else if(sjy1=="13C"&&sjy2=="13F"){
			cout<<100;
		}//3line
		else if(sjy1=="13D"&&sjy2=="13A"){
			cout<<100;
		}
		else if(sjy1=="13D"&&sjy2=="13C"){
			cout<<100;
		}
		else if(sjy1=="13D"&&sjy2=="13B"){
			cout<<100;
		}
		else if(sjy1=="13D"&&sjy2=="13F"){
			cout<<111;
		}//4line
		else if(sjy1=="13F"&&sjy2=="13A"){
			cout<<100;
		}
		else if(sjy1=="13F"&&sjy2=="13C"){
			cout<<100;
		}
		else if(sjy1=="13F"&&sjy2=="13D"){
			cout<<111;
		}
		else if(sjy1=="13F"&&sjy2=="13B"){
			cout<<100;
		}//5line    thirteenth cross
		else if(sjy1=="14A"&&sjy2=="14B"){
			cout<<111;
		}
		else if(sjy1=="14A"&&sjy2=="14C"){
			cout<<110;
		}
		else if(sjy1=="14A"&&sjy2=="14D"){
			cout<<100;
		}
		else if(sjy1=="14A"&&sjy2=="14F"){
			cout<<100;
		}//1line
		else if(sjy1=="14B"&&sjy2=="14A"){
			cout<<111;
		}
		else if(sjy1=="14B"&&sjy2=="14C"){
			cout<<111;
		}
		else if(sjy1=="14B"&&sjy2=="14D"){
			cout<<100;
		}
		else if(sjy1=="14B"&&sjy2=="14F"){
			cout<<100;
		}//2line
		else if(sjy1=="14C"&&sjy2=="14A"){
			cout<<110;
		}
		else if(sjy1=="14C"&&sjy2=="14B"){
			cout<<111;
		}
		else if(sjy1=="14C"&&sjy2=="14D"){
			cout<<100;
		}
		else if(sjy1=="14C"&&sjy2=="14F"){
			cout<<100;
		}//3line
		else if(sjy1=="14D"&&sjy2=="14A"){
			cout<<100;
		}
		else if(sjy1=="14D"&&sjy2=="14C"){
			cout<<100;
		}
		else if(sjy1=="14D"&&sjy2=="14B"){
			cout<<100;
		}
		else if(sjy1=="14D"&&sjy2=="14F"){
			cout<<111;
		}//4line
		else if(sjy1=="14F"&&sjy2=="14A"){
			cout<<100;
		}
		else if(sjy1=="14F"&&sjy2=="14C"){
			cout<<100;
		}
		else if(sjy1=="14F"&&sjy2=="14D"){
			cout<<111;
		}
		else if(sjy1=="14F"&&sjy2=="14B"){
			cout<<100;
		}//5line    fourteenth cross
		else if(sjy1=="15A"&&sjy2=="15B"){
			cout<<111;
		}
		else if(sjy1=="15A"&&sjy2=="15C"){
			cout<<110;
		}
		else if(sjy1=="15A"&&sjy2=="15D"){
			cout<<100;
		}
		else if(sjy1=="15A"&&sjy2=="15F"){
			cout<<100;
		}//1line
		else if(sjy1=="15B"&&sjy2=="15A"){
			cout<<111;
		}
		else if(sjy1=="15B"&&sjy2=="15C"){
			cout<<111;
		}
		else if(sjy1=="15B"&&sjy2=="15D"){
			cout<<100;
		}
		else if(sjy1=="15B"&&sjy2=="15F"){
			cout<<100;
		}//2line
		else if(sjy1=="15C"&&sjy2=="15A"){
			cout<<110;
		}
		else if(sjy1=="15C"&&sjy2=="15B"){
			cout<<111;
		}
		else if(sjy1=="15C"&&sjy2=="15D"){
			cout<<100;
		}
		else if(sjy1=="15C"&&sjy2=="15F"){
			cout<<100;
		}//3line
		else if(sjy1=="15D"&&sjy2=="15A"){
			cout<<100;
		}
		else if(sjy1=="15D"&&sjy2=="15C"){
			cout<<100;
		}
		else if(sjy1=="15D"&&sjy2=="15B"){
			cout<<100;
		}
		else if(sjy1=="15D"&&sjy2=="15F"){
			cout<<111;
		}//4line
		else if(sjy1=="15F"&&sjy2=="15A"){
			cout<<100;
		}
		else if(sjy1=="15F"&&sjy2=="15C"){
			cout<<100;
		}
		else if(sjy1=="15F"&&sjy2=="15D"){
			cout<<111;
		}
		else if(sjy1=="15F"&&sjy2=="15B"){
			cout<<100;
		}//5line    fifteenth cross
		else if(sjy1=="16A"&&sjy2=="16B"){
			cout<<111;
		}
		else if(sjy1=="16A"&&sjy2=="16C"){
			cout<<110;
		}
		else if(sjy1=="16A"&&sjy2=="16D"){
			cout<<100;
		}
		else if(sjy1=="16A"&&sjy2=="16F"){
			cout<<100;
		}//1line
		else if(sjy1=="16B"&&sjy2=="16A"){
			cout<<111;
		}
		else if(sjy1=="16B"&&sjy2=="16C"){
			cout<<111;
		}
		else if(sjy1=="16B"&&sjy2=="16D"){
			cout<<100;
		}
		else if(sjy1=="16B"&&sjy2=="16F"){
			cout<<100;
		}//2line
		else if(sjy1=="16C"&&sjy2=="16A"){
			cout<<110;
		}
		else if(sjy1=="16C"&&sjy2=="16B"){
			cout<<111;
		}
		else if(sjy1=="16C"&&sjy2=="16D"){
			cout<<100;
		}
		else if(sjy1=="16C"&&sjy2=="16F"){
			cout<<100;
		}//3line
		else if(sjy1=="16D"&&sjy2=="16A"){
			cout<<100;
		}
		else if(sjy1=="16D"&&sjy2=="16C"){
			cout<<100;
		}
		else if(sjy1=="16D"&&sjy2=="16B"){
			cout<<100;
		}
		else if(sjy1=="16D"&&sjy2=="16F"){
			cout<<111;
		}//4line
		else if(sjy1=="16F"&&sjy2=="16A"){
			cout<<100;
		}
		else if(sjy1=="16F"&&sjy2=="16C"){
			cout<<100;
		}
		else if(sjy1=="16F"&&sjy2=="16D"){
			cout<<111;
		}
		else if(sjy1=="16F"&&sjy2=="16B"){
			cout<<100;
		}//5line    sixteenth cross
		else{
			cout<<0;
		}
	}
	else{
		cout<<0000;
	} 
	return 0;
} 
