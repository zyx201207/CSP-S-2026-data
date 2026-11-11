// GZ-J00709 遵义市第十六中学 袁昊辰
#include <fstream>
#include <vector>

#define filename "string3"

struct Piece
{
	unsigned long long length;
	char letter;

	Piece(unsigned long len, char let): length(len), letter(let) {}
};

std::vector<Piece> str;

struct LetterHandle
{
	unsigned piece_i;
	unsigned long long letter_i;

	LetterHandle(unsigned p_i, unsigned long l_i): piece_i(p_i), letter_i(l_i) {}

	void operator+=(unsigned long movement)
	{
		movement += letter_i;
		letter_i = 0;

		while(movement >= str[piece_i].length)
		{
			movement -= str[piece_i].length;
			piece_i++;
		}

		letter_i += movement;
	}

	void operator-=(unsigned long movement)
	{
		if (movement >= letter_i)
		{
			movement -= letter_i;
			piece_i--;
			letter_i = str[piece_i].length;
		}
		else
		{
			letter_i -= movement;
			movement = 0;
		}

		while(movement >= str[piece_i].length)
		{
			movement -= str[piece_i].length;
			piece_i--;
		}

		letter_i = str[piece_i].length - movement;
	}
};

int main()
{
	std::ifstream inFile;
	std::ofstream outFile;
	inFile.open(filename ".in");
	outFile.open(filename ".out");

	unsigned pieceCount;
	inFile >> pieceCount;
	str.reserve(pieceCount);

	for (unsigned i = 0; i < pieceCount; i++)
	{
		unsigned length;
		char letter;
		inFile >> length >> letter;
		if (!str.empty() && str.back().letter == letter)
		{
			str.rbegin()->length += length;
		}
		else
		{
			str.emplace_back(length, letter);
		}
	}

	inFile.close();

	LetterHandle left(0, 1);
	LetterHandle right(str.size() - 1, str.rbegin()->length);

	unsigned long long operationCount = 0;

	while (true)
	{
		if (left.piece_i + 1 < right.piece_i)
		{
			unsigned long long movement = std::min(
			    str[left.piece_i].length - left.letter_i + 1,
			    right.letter_i
			);

			if (str[left.piece_i].letter != str[right.piece_i].letter)
			{
				operationCount += movement;
			}

			left += movement;
			right -= movement;
		}
		else if(left.piece_i < right.piece_i)
		{
			unsigned long long movement = (str[left.piece_i].length - left.letter_i + right.letter_i)/2;
			LetterHandle mid = left;
			mid += movement;
			if (mid.piece_i == left.piece_i)
			{
				operationCount += str[left.piece_i].length - mid.letter_i;
			}
			else
			{
				operationCount += mid.letter_i;
			}
			break;
		}
		else
		{
			break;
		}
	}

	outFile << operationCount;

	outFile.close();

	return 0;
}

