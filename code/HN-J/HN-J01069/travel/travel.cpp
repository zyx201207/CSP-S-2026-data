#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x;
	string r1,x1;
	cin>>r>>r1>>x>>x1;
	string r1v=r1;
	string x1v=x1;

	if(r==x) {
		cout<<1;
		if(r1v=="01A"&&x1v=="01B"||x1v=="01C") {
			cout<<1;
			if(r1v=="01A"&&x1v=="01B") {
				cout<<1<<1;
			}
		}
		if(r1v=="01B"&&x1v=="01A"||x1v=="01C") {
			cout<<1<<1<<1;
		}
		if(r1v=="01C"&&x1v=="01B"||x1v=="01A") {
			cout<<1;
			if(r1v=="01c"&&x1v=="01B") {
				cout<<1<<1;
			}
		}
		if(r1v=="02A"&&x1v=="02B"||x1v=="02C") {
			cout<<1;
			if(r1v=="02A"&&x1v=="02B") {
				cout<<1<<1;
			}
		}
		if(r1v=="02B"&&x1v=="02C"||x1v=="02A") {
			cout<<1<<1<<1;
		}
		if(r1v=="02C"&&x1v=="02B"||x1v=="02A") {
			cout<<1;
			if(r1v=="02c"&&x1v=="02B") {
				cout<<1<<1;
			}
		}
		if(r1v=="03A"&&x1v=="03B"||x1v=="03C") {
			cout<<1;
			if(r1v=="03A"&&x1v=="03B") {
				cout<<1<<1;
			}
		}
		if(r1v=="03B"&&x1v=="03A"||x1v=="03C") {
			cout<<1<<1<<1;
		}
		if(r1v=="03C"&&x1v=="03B"||x1v=="03A") {
			cout<<1;
			if(r1v=="03C"&&x1v=="03B") {
				cout<<1<<1;
			}
		}
		if(r1v=="04A"&&x1v=="04B"||x1v=="04C") {
			cout<<1;
			if(r1v=="04A"&&x1v=="04B") {
				cout<<1<<1<<1;
			}
		}
		if(r1v=="04B"&&x1v=="04A"||x1v=="04C") {
			cout<<1<<1<<1;
		}
		if(r1v=="04C"&&x1v=="04B"||x1v=="04A") {
			cout<<1;
			if(r1v=="04C"&&x1v=="04B") {
				cout<<1<<1;
			}
		}
		if(r1v=="05A"&&x1v=="05B"||x1v=="05C") {
			cout<<1;
			if(r1v=="05A"&&x1v=="05B") {
				cout<<1<<1;
			}
		}
		if(r1v=="05B"&&x1v=="05C"||x1v=="05A") {
			cout<<1<<1<<1;
		}
		if(r1v=="05C"&&x1v=="05B"||x1v=="05A") {
			cout<<1;
			if(r1v=="05C"&&x1v=="05B") {
				cout<<1<<1;
			}
		}
		if(r1v=="06A"&&x1v=="06C"||x1v=="06B") {
			cout<<1;
			if(r1v=="06A"&&x1v=="06B") {
				cout<<1<<1;
			}
		}
		if(r1v=="06B"&&x1v=="06A"||x1v=="06C") {
			cout<<1<<1<<1;
		}
		if(r1v=="06C"&&x1v=="06A"||x1v=="06B") {
			cout<<1;
			if(r1v=="06C"&&x1v=="06A") {
				cout<<1<<1;
			}
		}
		if(r1v=="07A"&&x1v=="07C"||x1v=="07B") {
			cout<<1;
			if(r1v=="07A"&&x1v=="07C") {
				cout<<1<<1;
			}
		}
		if(r1v=="07B"&&x1v=="07C"||x1v=="07A") {
			cout<<1<<1<<1;
		}
		if(r1v=="07C"&&x1v=="07A"||x1v=="07B") {
			cout<<1;
			if(r1v=="07C"&&x1v=="07A") {
				cout<<1<<1;
			}
		}
		if(r1v=="08A"&&x1v=="08C"||x1v=="08B") {
			cout<<1;
			if(r1v=="08A"&&x1v=="08C") {
				cout<<1<<1;
			}
		}
		if(r1v=="08B"&&x1v=="08C"||x1v=="08A") {
			cout<<1<<1<<1;
		}
		if(r1v=="08C"&&x1v=="08A"||x1v=="08B") {
			cout<<1;
			if(r1v=="08C"&&x1v=="08A") {
				cout<<1<<1;
			}
		}
		if(r1v=="09A"&&x1v=="09C"||x1v=="09B") {
			cout<<1;
			if(r1v=="09A"&&x1v=="09C") {
				cout<<1<<1;
			}
		}
		if(r1v=="09B"&&x1v=="09C"||x1v=="09A") {
			cout<<1<<1<<1;
		}
		if(r1v=="09C"&&x1v=="09A"||x1v=="09B") {
			cout<<1;
			if(r1v=="09C"&&x1v=="09A") {
				cout<<1<<1;
			}
		}
		if(r1v=="10A"&&x1v=="10C"||x1v=="10B") {
			cout<<1;
			if(r1v=="10A"&&x1v=="10C") {
				cout<<1<<1;
			}
		}
		if(r1v=="10B"&&x1v=="10C"||x1v=="10A") {
			cout<<1<<1<<1;
		}
		if(r1v=="10C"&&x1v=="10A"||x1v=="10B") {
			cout<<1;
			if(r1v=="10C"&&x1v=="10A") {
				cout<<1<<1;
			}
		}
		if(r1v=="11A"&&x1v=="11C"||x1v=="11B") {
			cout<<1;
			if(r1v=="11A"&&x1v=="11C") {
				cout<<1<<1;
			}
		}
		if(r1v=="11B"&&x1v=="11C"||x1v=="11A") {
			cout<<1<<1<<1;
		}
		if(r1v=="11C"&&x1v=="11B"||x1v=="11A") {
			cout<<1;
			if(r1v=="11C"&&x1v=="11B") {
				cout<<1<<1;
			}
		}
		if(r1v=="12B"&&x1v=="12C"||x1v=="12A") {
			cout<<1<<1<<1;
		}
		if(r1v=="12A"&&x1v=="12C"||x1v=="12B") {
			cout<<1;
		}
		if(r1v=="12C"&&x1v=="12B"||x1v=="12A") {
			cout<<1;
		}
		if(r1v=="13A"&&x1v=="13B"||x1v=="13C") {
			cout<<1;
		}
		if(r1v=="13B"&&x1v=="13A"||x1v=="13C") {
			cout<<1<<1<<1;
		}
		if(r1v=="13C"&&x1v=="13B"||x1v=="13A") {
			cout<<1;
		}
		if(r1v=="14A"&&x1v=="14B"||x1v=="14C") {
			cout<<1;
		}
		if(r1v=="14B"&&x1v=="14A"||x1v=="14C") {
			cout<<1<<1<<1;
		}
		if(r1v=="14C"&&x1v=="14B"||x1v=="14A") {
			cout<<1;
		}
		if(r1v=="15A"&&x1v=="15B"||x1v=="15C") {
			cout<<1;
		}
		if(r1v=="15B"&&x1v=="15A"||x1v=="15C") {
			cout<<1<<1<<1;
		}
		if(r1v=="15C"&&x1v=="15B"||x1v=="15A") {
			cout<<1;
		}
		if(r1v=="16A"&&x1v=="16B"||x1v=="16C") {
			cout<<1;
		}
		if(r1v=="16B"&&x1v=="16A"||x1v=="16C") {
			cout<<1<<1<<1;
		}
		if(r1v=="16C"&&x1v=="16B"||x1v=="16A") {
			cout<<1;
		}
		if(r1v=="17A"&&x1v=="17B"||x1v=="17C") {
			cout<<1;
		}
		if(r1v=="17B"&&x1v=="17A"||x1v=="17C") {
			cout<<1<<1<<1;
		}
		if(r1v=="17C"&&x1v=="17B"||x1v=="17A") {
			cout<<1;
		}
		if(r1v=="18A"&&x1v=="18B"||x1v=="18C") {
			cout<<1;
		}
		if(r1v=="18B"&&x1v=="18A"||x1v=="18C") {
			cout<<1<<1<<1;
		}
		if(r1v=="18C"&&x1v=="18B"||x1v=="18A") {
			cout<<1;
		} else {
				
		}

	} else {
		cout<<0000;
	}
	return 0;
}

