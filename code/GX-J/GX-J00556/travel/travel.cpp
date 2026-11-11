#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rx,rw,xx,xw;
	cin>>rx>>rw>>xx>>xw;
	if(rx==xx){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
//01A
	if(rw=="01A"){
		if(xw=="01B"){
			cout<<"111";
			return 0;
		}
		if(xw=="01C"){
			cout<<"110";
			return 0;
		}
		if(xw=="01D" || xw=="01F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//01B
	if(rw=="01B"){
		if(xw=="01A" || xw=="01C"){
			cout<<"111";
			return 0;
		}
		if(xw=="01D" || xw=="01F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//01C
	if(rw=="01C"){
		if(xw=="01B"){
			cout<<"111";
			return 0;
		}
		if(xw=="01A"){
			cout<<"110";
			return 0;
		}
		if(xw=="01D" || xw=="01F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//01D
	if(rw=="01D"){
		if(xw=="01F"){
			cout<<"111";
			return 0;
		}
		if(xw=="01A" || xw=="01B" || xw=="01C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//01F
	if(rw=="01F"){
		if(xw=="01D"){
			cout<<"111";
			return 0;
		}
		if(xw=="01A" || xw=="01B",xw=="01C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//02A
	if(rw=="02A"){
		if(xw=="02B"){
			cout<<"111";
			return 0;
		}
		if(xw=="02C"){
			cout<<"110";
			return 0;
		}
		if(xw=="02D" || xw=="02F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//02B
	if(rw=="02B"){
		if(xw=="02A" || xw=="02C"){
			cout<<"111";
			return 0;
		}
		if(xw=="02D" || xw=="02F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//02C
	if(rw=="02C"){
		if(xw=="02B"){
			cout<<"111";
			return 0;
		}
		if(xw=="02A"){
			cout<<"110";
			return 0;
		}
		if(xw=="02D" || xw=="02F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//02D
	if(rw=="02D"){
		if(xw=="02F"){
			cout<<"111";
			return 0;
		}
		if(xw=="02A" || xw=="02B" || xw=="02C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//02F
	if(rw=="02F"){
		if(xw=="02D"){
			cout<<"111";
			return 0;
		}
		if(xw=="02A" || xw=="02B",xw=="02C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//03A
	if(rw=="03A"){
		if(xw=="03B"){
			cout<<"111";
			return 0;
		}
		if(xw=="03C"){
			cout<<"110";
			return 0;
		}
		if(xw=="03D" || xw=="03F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//03B
	if(rw=="03B"){
		if(xw=="03A" || xw=="03C"){
			cout<<"111";
			return 0;
		}
		if(xw=="03D" || xw=="03F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//03C
	if(rw=="03C"){
		if(xw=="03B"){
			cout<<"111";
			return 0;
		}
		if(xw=="03A"){
			cout<<"110";
			return 0;
		}
		if(xw=="03D" || xw=="03F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//03D
	if(rw=="03D"){
		if(xw=="03F"){
			cout<<"111";
			return 0;
		}
		if(xw=="03A" || xw=="03B" || xw=="03C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//03F
	if(rw=="03F"){
		if(xw=="03D"){
			cout<<"111";
			return 0;
		}
		if(xw=="03A" || xw=="03B",xw=="03C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//04A
	if(rw=="04A"){
		if(xw=="04B"){
			cout<<"111";
			return 0;
		}
		if(xw=="04C"){
			cout<<"110";
			return 0;
		}
		if(xw=="04D" || xw=="04F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//04B
	if(rw=="04B"){
		if(xw=="04A" || xw=="04C"){
			cout<<"111";
			return 0;
		}
		if(xw=="04D" || xw=="04F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//04C
	if(rw=="04C"){
		if(xw=="04B"){
			cout<<"111";
			return 0;
		}
		if(xw=="04A"){
			cout<<"110";
			return 0;
		}
		if(xw=="04D" || xw=="04F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//04D
	if(rw=="04D"){
		if(xw=="04F"){
			cout<<"111";
			return 0;
		}
		if(xw=="04A" || xw=="04B" || xw=="04C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//04F
	if(rw=="04F"){
		if(xw=="04D"){
			cout<<"111";
			return 0;
		}
		if(xw=="04A" || xw=="04B",xw=="04C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//05A
	if(rw=="05A"){
		if(xw=="05B"){
			cout<<"111";
			return 0;
		}
		if(xw=="05C"){
			cout<<"110";
			return 0;
		}
		if(xw=="05D" || xw=="05F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//05B
	if(rw=="05B"){
		if(xw=="05A" || xw=="05C"){
			cout<<"111";
			return 0;
		}
		if(xw=="05D" || xw=="05F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//05C
	if(rw=="05C"){
		if(xw=="05B"){
			cout<<"111";
			return 0;
		}
		if(xw=="05A"){
			cout<<"110";
			return 0;
		}
		if(xw=="05D" || xw=="05F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//05D
	if(rw=="05D"){
		if(xw=="05F"){
			cout<<"111";
			return 0;
		}
		if(xw=="05A" || xw=="05B" || xw=="05C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//05F
	if(rw=="05F"){
		if(xw=="05D"){
			cout<<"111";
			return 0;
		}
		if(xw=="05A" || xw=="05B",xw=="05C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//06A
	if(rw=="06A"){
		if(xw=="06B"){
			cout<<"111";
			return 0;
		}
		if(xw=="06C"){
			cout<<"110";
			return 0;
		}
		if(xw=="06D" || xw=="06F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//06B
	if(rw=="06B"){
		if(xw=="06A" || xw=="06C"){
			cout<<"111";
			return 0;
		}
		if(xw=="06D" || xw=="06F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//06C
	if(rw=="06C"){
		if(xw=="06B"){
			cout<<"111";
			return 0;
		}
		if(xw=="06A"){
			cout<<"110";
			return 0;
		}
		if(xw=="06D" || xw=="06F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//06D
	if(rw=="06D"){
		if(xw=="06F"){
			cout<<"111";
			return 0;
		}
		if(xw=="06A" || xw=="06B" || xw=="06C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//06F
	if(rw=="06F"){
		if(xw=="06D"){
			cout<<"111";
			return 0;
		}
		if(xw=="06A" || xw=="06B",xw=="06C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//07A
	if(rw=="07A"){
		if(xw=="07B"){
			cout<<"111";
			return 0;
		}
		if(xw=="07C"){
			cout<<"110";
			return 0;
		}
		if(xw=="07D" || xw=="07F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//07B
	if(rw=="07B"){
		if(xw=="07A" || xw=="07C"){
			cout<<"111";
			return 0;
		}
		if(xw=="07D" || xw=="07F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//07C
	if(rw=="07C"){
		if(xw=="07B"){
			cout<<"111";
			return 0;
		}
		if(xw=="07A"){
			cout<<"110";
			return 0;
		}
		if(xw=="07D" || xw=="07F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//07D
	if(rw=="07D"){
		if(xw=="07F"){
			cout<<"111";
			return 0;
		}
		if(xw=="07A" || xw=="07B" || xw=="07C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//07F
	if(rw=="07F"){
		if(xw=="07D"){
			cout<<"111";
			return 0;
		}
		if(xw=="07A" || xw=="07B",xw=="07C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//08A
	if(rw=="08A"){
		if(xw=="08B"){
			cout<<"111";
			return 0;
		}
		if(xw=="08C"){
			cout<<"110";
			return 0;
		}
		if(xw=="08D" || xw=="08F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//08B
	if(rw=="08B"){
		if(xw=="08A" || xw=="08C"){
			cout<<"111";
			return 0;
		}
		if(xw=="08D" || xw=="08F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//08C
	if(rw=="08C"){
		if(xw=="08B"){
			cout<<"111";
			return 0;
		}
		if(xw=="08A"){
			cout<<"110";
			return 0;
		}
		if(xw=="08D" || xw=="08F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//08D
	if(rw=="08D"){
		if(xw=="08F"){
			cout<<"111";
			return 0;
		}
		if(xw=="08A" || xw=="08B" || xw=="08C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//08F
	if(rw=="08F"){
		if(xw=="08D"){
			cout<<"111";
			return 0;
		}
		if(xw=="08A" || xw=="08B",xw=="08C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//09A
	if(rw=="09A"){
		if(xw=="09B"){
			cout<<"111";
			return 0;
		}
		if(xw=="09C"){
			cout<<"110";
			return 0;
		}
		if(xw=="09D" || xw=="09F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//09B
	if(rw=="09B"){
		if(xw=="09A" || xw=="09C"){
			cout<<"111";
			return 0;
		}
		if(xw=="09D" || xw=="09F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//09C
	if(rw=="09C"){
		if(xw=="09B"){
			cout<<"111";
			return 0;
		}
		if(xw=="09A"){
			cout<<"110";
			return 0;
		}
		if(xw=="09D" || xw=="09F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//09D
	if(rw=="09D"){
		if(xw=="09F"){
			cout<<"111";
			return 0;
		}
		if(xw=="09A" || xw=="09B" || xw=="09C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//09F
	if(rw=="09F"){
		if(xw=="09D"){
			cout<<"111";
			return 0;
		}
		if(xw=="09A" || xw=="09B",xw=="09C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//10A
	if(rw=="10A"){
		if(xw=="10B"){
			cout<<"111";
			return 0;
		}
		if(xw=="10C"){
			cout<<"110";
			return 0;
		}
		if(xw=="10D" || xw=="10F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//10B
	if(rw=="10B"){
		if(xw=="10A" || xw=="10C"){
			cout<<"111";
			return 0;
		}
		if(xw=="10D" || xw=="10F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//10C
	if(rw=="10C"){
		if(xw=="10B"){
			cout<<"111";
			return 0;
		}
		if(xw=="10A"){
			cout<<"110";
			return 0;
		}
		if(xw=="10D" || xw=="10F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//10D
	if(rw=="10D"){
		if(xw=="10F"){
			cout<<"111";
			return 0;
		}
		if(xw=="10A" || xw=="10B" || xw=="10C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//10F
	if(rw=="10F"){
		if(xw=="10D"){
			cout<<"111";
			return 0;
		}
		if(xw=="10A" || xw=="10B",xw=="10C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//11A
	if(rw=="11A"){
		if(xw=="11B"){
			cout<<"111";
			return 0;
		}
		if(xw=="11C"){
			cout<<"110";
			return 0;
		}
		if(xw=="11D" || xw=="11F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//11B
	if(rw=="11B"){
		if(xw=="11A" || xw=="11C"){
			cout<<"111";
			return 0;
		}
		if(xw=="11D" || xw=="11F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//11C
	if(rw=="11C"){
		if(xw=="11B"){
			cout<<"111";
			return 0;
		}
		if(xw=="11A"){
			cout<<"110";
			return 0;
		}
		if(xw=="11D" || xw=="11F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//11D
	if(rw=="11D"){
		if(xw=="11F"){
			cout<<"111";
			return 0;
		}
		if(xw=="11A" || xw=="11B" || xw=="11C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//11F
	if(rw=="11F"){
		if(xw=="11D"){
			cout<<"111";
			return 0;
		}
		if(xw=="11A" || xw=="11B",xw=="11C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//12A
	if(rw=="12A"){
		if(xw=="12B"){
			cout<<"111";
			return 0;
		}
		if(xw=="12C"){
			cout<<"110";
			return 0;
		}
		if(xw=="12D" || xw=="12F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//12B
	if(rw=="12B"){
		if(xw=="12A" || xw=="12C"){
			cout<<"111";
			return 0;
		}
		if(xw=="12D" || xw=="12F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//12C
	if(rw=="12C"){
		if(xw=="12B"){
			cout<<"111";
			return 0;
		}
		if(xw=="12A"){
			cout<<"110";
			return 0;
		}
		if(xw=="12D" || xw=="12F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//12D
	if(rw=="12D"){
		if(xw=="12F"){
			cout<<"111";
			return 0;
		}
		if(xw=="12A" || xw=="12B" || xw=="12C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//12F
	if(rw=="12F"){
		if(xw=="12D"){
			cout<<"111";
			return 0;
		}
		if(xw=="12A" || xw=="12B",xw=="12C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//13A
	if(rw=="13A"){
		if(xw=="13B"){
			cout<<"111";
			return 0;
		}
		if(xw=="13C"){
			cout<<"110";
			return 0;
		}
		if(xw=="13D" || xw=="13F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//13B
	if(rw=="13B"){
		if(xw=="13A" || xw=="13C"){
			cout<<"111";
			return 0;
		}
		if(xw=="13D" || xw=="13F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//13C
	if(rw=="13C"){
		if(xw=="13B"){
			cout<<"111";
			return 0;
		}
		if(xw=="13A"){
			cout<<"110";
			return 0;
		}
		if(xw=="13D" || xw=="13F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//13D
	if(rw=="13D"){
		if(xw=="13F"){
			cout<<"111";
			return 0;
		}
		if(xw=="13A" || xw=="13B" || xw=="13C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//13F
	if(rw=="13F"){
		if(xw=="13D"){
			cout<<"111";
			return 0;
		}
		if(xw=="13A" || xw=="13B",xw=="13C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//14A
	if(rw=="14A"){
		if(xw=="14B"){
			cout<<"111";
			return 0;
		}
		if(xw=="14C"){
			cout<<"110";
			return 0;
		}
		if(xw=="14D" || xw=="14F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//14B
	if(rw=="14B"){
		if(xw=="14A" || xw=="14C"){
			cout<<"111";
			return 0;
		}
		if(xw=="14D" || xw=="14F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//14C
	if(rw=="14C"){
		if(xw=="14B"){
			cout<<"111";
			return 0;
		}
		if(xw=="14A"){
			cout<<"110";
			return 0;
		}
		if(xw=="14D" || xw=="14F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//14D
	if(rw=="14D"){
		if(xw=="14F"){
			cout<<"111";
			return 0;
		}
		if(xw=="14A" || xw=="14B" || xw=="14C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//14F
	if(rw=="14F"){
		if(xw=="14D"){
			cout<<"111";
			return 0;
		}
		if(xw=="14A" || xw=="14B",xw=="14C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//15A
	if(rw=="15A"){
		if(xw=="15B"){
			cout<<"111";
			return 0;
		}
		if(xw=="15C"){
			cout<<"110";
			return 0;
		}
		if(xw=="15D" || xw=="15F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//15B
	if(rw=="15B"){
		if(xw=="15A" || xw=="15C"){
			cout<<"111";
			return 0;
		}
		if(xw=="15D" || xw=="15F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//15C
	if(rw=="15C"){
		if(xw=="15B"){
			cout<<"111";
			return 0;
		}
		if(xw=="15A"){
			cout<<"110";
			return 0;
		}
		if(xw=="15D" || xw=="15F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//15D
	if(rw=="15D"){
		if(xw=="15F"){
			cout<<"111";
			return 0;
		}
		if(xw=="15A" || xw=="15B" || xw=="15C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//15F
	if(rw=="15F"){
		if(xw=="15D"){
			cout<<"111";
			return 0;
		}
		if(xw=="15A" || xw=="15B",xw=="15C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//16A
	if(rw=="16A"){
		if(xw=="16B"){
			cout<<"111";
			return 0;
		}
		if(xw=="16C"){
			cout<<"110";
			return 0;
		}
		if(xw=="16D" || xw=="16F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//16B
	if(rw=="16B"){
		if(xw=="16A" || xw=="16C"){
			cout<<"111";
			return 0;
		}
		if(xw=="16D" || xw=="16F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//16C
	if(rw=="16C"){
		if(xw=="16B"){
			cout<<"111";
			return 0;
		}
		if(xw=="16A"){
			cout<<"110";
			return 0;
		}
		if(xw=="16D" || xw=="16F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//16D
	if(rw=="16D"){
		if(xw=="16F"){
			cout<<"111";
			return 0;
		}
		if(xw=="16A" || xw=="16B" || xw=="16C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//16F
	if(rw=="16F"){
		if(xw=="16D"){
			cout<<"111";
			return 0;
		}
		if(xw=="16A" || xw=="16B",xw=="16C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//17A
	if(rw=="17A"){
		if(xw=="17B"){
			cout<<"111";
			return 0;
		}
		if(xw=="17C"){
			cout<<"110";
			return 0;
		}
		if(xw=="17D" || xw=="17F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//17B
	if(rw=="17B"){
		if(xw=="17A" || xw=="17C"){
			cout<<"111";
			return 0;
		}
		if(xw=="17D" || xw=="17F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//17C
	if(rw=="17C"){
		if(xw=="17B"){
			cout<<"111";
			return 0;
		}
		if(xw=="17A"){
			cout<<"110";
			return 0;
		}
		if(xw=="17D" || xw=="17F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//17D
	if(rw=="17D"){
		if(xw=="17F"){
			cout<<"111";
			return 0;
		}
		if(xw=="17A" || xw=="17B" || xw=="17C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//17F
	if(rw=="17F"){
		if(xw=="17D"){
			cout<<"111";
			return 0;
		}
		if(xw=="17A" || xw=="17B",xw=="17C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//18A
	if(rw=="18A"){
		if(xw=="18B"){
			cout<<"111";
			return 0;
		}
		if(xw=="18C"){
			cout<<"110";
			return 0;
		}
		if(xw=="18D" || xw=="18F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//18B
	if(rw=="18B"){
		if(xw=="18A" || xw=="18C"){
			cout<<"111";
			return 0;
		}
		if(xw=="18D" || xw=="18F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//18C
	if(rw=="18C"){
		if(xw=="18B"){
			cout<<"111";
			return 0;
		}
		if(xw=="18A"){
			cout<<"110";
			return 0;
		}
		if(xw=="18D" || xw=="18F"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//18D
	if(rw=="18D"){
		if(xw=="18F"){
			cout<<"111";
			return 0;
		}
		if(xw=="18A" || xw=="18B" || xw=="18C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
//18F
	if(rw=="18F"){
		if(xw=="18D"){
			cout<<"111";
			return 0;
		}
		if(xw=="18A" || xw=="18B",xw=="18C"){
			cout<<"100";
			return 0;
		}else{
			cout<<"000";
			return 0;
		}
	}
	return 0;
}
